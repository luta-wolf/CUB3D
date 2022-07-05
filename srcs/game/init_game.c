/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:10:28 by drayl             #+#    #+#             */
/*   Updated: 2022/03/13 15:10:30 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	extract_data_from_map(t_game *game, t_map *map)
{
	char	sym;

	sym = map->player_side;
	game->map = map->map;
	game->player.x = (double) map->player_x + 0.5;
	game->player.y = (double) map->player_y + 0.5;
	game->dir.x = (sym == SIDE_E) - (sym == SIDE_W);
	game->dir.y = (sym == SIDE_S) - (sym == SIDE_N);
	game->plane.x = game->dir.y * -PLANE;
	game->plane.y = game->dir.x * -PLANE;
	game->mini_map.height = map->height;
	game->mini_map.width = map->width;
	game->mini_map.start.x = SCREEN_WIDTH - map->width * BLOCK_SIZE;
	game->mini_map.start.y = SCREEN_HEIGHT - map->height * BLOCK_SIZE;
	game->mini_map.pos.x = map->player_x;
	game->mini_map.pos.y = map->player_y;
}

static void	init_color(t_game *game, t_data *data)
{
	game->c_color = (data->ceilling->r * 256 + data->ceilling->g) \
	* 256 + data->ceilling->b;
	game->f_color = (data->floor->r * 256 + data->floor->g) \
	* 256 + data->floor->b;
	game->mini_map.p_color = 0x4a0a21;
	game->mini_map.b_color = 0x0b053d;
	game->mini_map.e_color = 0x9990e8;
}

t_game	*init_game(t_data *data)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof (t_game));
	if (game == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	extract_data_from_map(game, data->map);
	init_mlx(game, data);
	init_color(game, data);
	draw_mini_map(game);
	return (game);
}
