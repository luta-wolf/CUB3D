/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:08:58 by drayl             #+#    #+#             */
/*   Updated: 2022/03/13 15:08:59 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_block(t_tex *scr, int start_x, int start_y, int color)
{
	int			x;
	int			y;
	t_icoord	pos;

	y = -1;
	while (++y < BLOCK_SIZE)
	{
		x = -1;
		while (++x < BLOCK_SIZE)
		{
			pos.x = start_x + x;
			pos.y = start_y + y;
			draw_pixel(scr, pos, color);
		}
	}
}

void	draw_mini_map(t_game *game)
{
	int			x;
	int			y;
	t_icoord	pix;

	y = -1;
	while (game->map[++y] != NULL && y < game->mini_map.height)
	{
		x = -1;
		while (game->map[y][++x] != END_OF_LINE && x < game->mini_map.width)
		{
			pix.x = game->mini_map.start.x + x * BLOCK_SIZE;
			pix.y = game->mini_map.start.y + y * BLOCK_SIZE;
			if (game->map[y][x] == BLOCK || game->map[y][x] == SPACE)
				draw_block(&game->screen, pix.x, pix.y, game->mini_map.b_color);
			else if (game->map[y][x] == EMPTY)
				draw_block(&game->screen, pix.x, pix.y, game->mini_map.e_color);
			else
				draw_block(&game->screen, pix.x, pix.y, game->mini_map.p_color);
		}
	}
}
