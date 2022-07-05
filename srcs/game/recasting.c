/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:10:34 by drayl             #+#    #+#             */
/*   Updated: 2022/03/13 15:10:35 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	init_start_param(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / SCREEN_WIDTH - 1;
	ray->ray_pos.x = game->player.x;
	ray->ray_pos.y = game->player.y;
	ray->map_pos.x = (int) game->player.x;
	ray->map_pos.y = (int) game->player.y;
	ray->ray_dir.x = game->dir.x + game->plane.x * ray->camera_x;
	ray->ray_dir.y = game->dir.y + game->plane.y * ray->camera_x;
	ray->step.x = (ray->ray_dir.x >= 0) - (ray->ray_dir.x < 0);
	ray->step.y = (ray->ray_dir.y >= 0) - (ray->ray_dir.y < 0);
	ray->delta_dist.x = fabs(1.0 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1.0 / ray->ray_dir.y);
	ray->side_dist.x = (ray->map_pos.x - ray->ray_pos.x + (ray->step.x >= 0)) \
	* ray->step.x * ray->delta_dist.x;
	ray->side_dist.y = (ray->map_pos.y - ray->ray_pos.y + (ray->step.y >= 0)) \
	* ray->step.y * ray->delta_dist.y;
}

static void	init_other_info(t_game *game, t_ray *ray)
{
	int	next_side;

	while (TRUE)
	{
		next_side = (ray->side_dist.x < ray->side_dist.y);
		ray->side_dist.x += (ray->delta_dist.x * next_side);
		ray->side_dist.y += (ray->delta_dist.y * !next_side);
		ray->map_pos.x += (ray->step.x * next_side);
		ray->map_pos.y += (ray->step.y * !next_side);
		ray->side = !next_side;
		if (game->map[ray->map_pos.y][ray->map_pos.x] == BLOCK)
			break ;
	}
	if (ray->side)
		ray->distance = fabs((ray->map_pos.y - game->player.y \
		+ (1.0 - ray->step.y) / 2) / ray->ray_dir.y);
	else
		ray->distance = fabs((ray->map_pos.x - game->player.x \
		+ (1.0 - ray->step.x) / 2) / ray->ray_dir.x);
	if (ray->side)
		ray->direction = E_NORTH + (ray->ray_dir.y >= 0);
	else
		ray->direction = E_WEST + (ray->ray_dir.x >= 0);
	ray->height = (int) fabs(SCREEN_HEIGHT / ray->distance);
}

static void	update_map(t_game *g)
{
	t_icoord	pix;

	if ((int) g->player.x == g->mini_map.pos.x
		&& (int) g->player.y == g->mini_map.pos.y)
		return ;
	pix.x = g->mini_map.start.x + g->mini_map.pos.x * BLOCK_SIZE;
	pix.y = g->mini_map.start.y + g->mini_map.pos.y * BLOCK_SIZE;
	draw_block(&g->screen, pix.x, pix.y, g->mini_map.e_color);
	g->mini_map.pos.x = (int) g->player.x;
	g->mini_map.pos.y = (int) g->player.y;
	pix.x = g->mini_map.start.x + g->mini_map.pos.x * BLOCK_SIZE;
	pix.y = g->mini_map.start.y + g->mini_map.pos.y * BLOCK_SIZE;
	draw_block(&g->screen, pix.x, pix.y, g->mini_map.p_color);
}

int	recasting(t_game *game)
{
	int		x;
	t_ray	ray;

	mlx_mouse_get_pos(game->win_ptr, &ray.mouse.x, &ray.mouse.y);
	if (game->mouse.x != ray.mouse.x)
		rotate_for_mouse(game, &ray.mouse);
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		init_start_param(game, &ray, x);
		init_other_info(game, &ray);
		draw_wall(game, &ray, x);
	}
	update_map(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->screen.img, 0, 0);
	return (OK);
}
