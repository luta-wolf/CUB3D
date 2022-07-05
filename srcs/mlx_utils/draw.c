/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:08:51 by drayl             #+#    #+#             */
/*   Updated: 2022/03/13 15:08:52 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_pixel(t_tex *scr, t_icoord pos, int color)
{
	if (pos.x >= 0 && pos.y >= 0
		&& pos.x < SCREEN_WIDTH && pos.y < SCREEN_HEIGHT)
		*(int *)(scr->adr + (scr->len * pos.y) \
		+ (scr->bpp * pos.x / 8)) = color;
}

int	get_tex_color(t_tex *tex, t_icoord pos)
{
	if (pos.x >= 0 && pos.y >= 0
		&& pos.x < TEX_WIDTH && pos.y < TEX_HEIGHT)
		return (*(int *)(tex->adr + (tex->len * pos.y) \
		+ (tex->bpp * pos.x / 8)));
	return (0x0);
}

void	draw_line(t_game *game, t_icoord pos, int end)
{
	int			i;
	t_icoord	pix;

	i = -1;
	pix.x = pos.x;
	while (++i < pos.y)
	{
		pix.y = i;
		if (pix.x >= game->mini_map.start.x && pix.y >= game->mini_map.start.y)
			break ;
		draw_pixel(&game->screen, pix, game->c_color);
	}
	i = end - 1;
	while (++i < SCREEN_HEIGHT)
	{
		pix.y = i;
		if (pix.x >= game->mini_map.start.x && pix.y >= game->mini_map.start.y)
			break ;
		draw_pixel(&game->screen, pix, game->f_color);
	}
}

static void	init_tex_pos(t_ray *r, t_tex *tex, t_icoord *tex_pos)
{
	if (r->side)
		r->wall_x = r->ray_pos.x + ((r->map_pos.y - r->ray_pos.y \
		+ (1.0 - r->step.y) / 2) / r->ray_dir.y) * r->ray_dir.x;
	else
		r->wall_x = r->ray_pos.y + ((r->map_pos.x - r->ray_pos.x \
		+ (1.0 - r->step.x) / 2) / r->ray_dir.x) * r->ray_dir.y;
	r->wall_x -= floor(r->wall_x);
	tex_pos->x = (int)(r->wall_x * tex->width);
	if (r->side == E_HORIZONTAL && r->ray_dir.x > 0)
		tex_pos->x = tex->width - tex_pos->x - 1;
	if (r->side == E_VERTICAL && r->ray_dir.y < 0)
		tex_pos->x = tex->width - tex_pos->x - 1;
}

void	draw_wall(t_game *game, t_ray *r, int x)
{
	int			tex_end;
	t_tex		*tex;
	t_icoord	pix;
	t_icoord	tex_pos;

	tex = &game->texture[r->direction];
	pix.x = x;
	pix.y = (int)((SCREEN_HEIGHT - r->height) \
	/ 2.0 * ((SCREEN_HEIGHT - r->height) > 0));
	tex_end = (int)((SCREEN_HEIGHT + r->height) / 2.0);
	if (tex_end > SCREEN_HEIGHT)
		tex_end = SCREEN_HEIGHT;
	draw_line(game, pix, tex_end);
	init_tex_pos(r, tex, &tex_pos);
	--pix.y;
	while (++pix.y < tex_end)
	{
		if (pix.x >= game->mini_map.start.x && pix.y >= game->mini_map.start.y)
			break ;
		tex_pos.y = (int)((pix.y * 2.0 - SCREEN_HEIGHT + r->height) \
		* ((tex->height / 2.0) / r->height));
		draw_pixel(&game->screen, pix, get_tex_color(tex, tex_pos));
	}
}
