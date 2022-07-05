/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:09:27 by drayl             #+#    #+#             */
/*   Updated: 2022/03/13 15:09:28 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	move_pos(t_game *game, int key)
{
	t_coord	move_pos;
	int		dir;

	dir = (key == KEY_W || key == KEY_UP) - (key == KEY_S || key == KEY_DOWN);
	move_pos.x = game->dir.x * STEP * dir;
	move_pos.y = game->dir.y * STEP * dir;
	if (game->map[(int)(game->player.y + move_pos.y)] \
	[(int)game->player.x] == BLOCK)
		move_pos.y = 0;
	if (game->map[(int)game->player.y] \
	[(int)(game->player.x + move_pos.x)] == BLOCK)
		move_pos.x = 0;
	game->player.y += move_pos.y;
	game->player.x += move_pos.x;
}

void	move_pos2(t_game *game, int key)
{
	int		dir;
	t_coord	move_pos;

	dir = (key == KEY_D) - (key == KEY_A);
	move_pos.x = game->plane.x * STEP * dir;
	move_pos.y = game->plane.y * STEP * dir;
	if (game->map[(int)(game->player.y + move_pos.y + 0.00001)] \
	[(int)game->player.x] == BLOCK)
		move_pos.y = 0;
	if (game->map[(int)game->player.y] \
	[(int)(game->player.x + move_pos.x + 0.00001)] == BLOCK)
		move_pos.x = 0;
	game->player.y += move_pos.y;
	game->player.x += move_pos.x;
}

static void	rotate(t_game *game, int key, double speed)
{
	double	dir;
	double	dir_buff;
	double	plane_buff;

	dir_buff = game->dir.x;
	plane_buff = game->plane.x;
	dir = ((key == KEY_RIGHT) - (key == KEY_LEFT)) * ROT * speed;
	game->dir.x = game->dir.x * cos(dir) - game->dir.y * sin(dir);
	game->dir.y = dir_buff * sin(dir) + game->dir.y * cos(dir);
	game->plane.x = game->plane.x * cos(dir) - game->plane.y * sin(dir);
	game->plane.y = plane_buff * sin(dir) + game->plane.y * cos(dir);
}

void	rotate_for_mouse(t_game *game, t_icoord *mouse)
{
	if (mouse->x > game->mouse.x)
		rotate(game, KEY_RIGHT, SMALL);
	else
		rotate(game, KEY_LEFT, SMALL);
	mlx_mouse_move(game->win_ptr, game->mouse.x, game->mouse.y);
}

int	key_manager(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_ok(key);
	else if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN)
		move_pos(game, key);
	else if (key == KEY_D || key == KEY_A)
		move_pos2(game, key);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate(game, key, STANDARD);
	return (OK);
}
