/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:07:54 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:07:56 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_map	*create_map(void)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof (t_map));
	if (map == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	map->width = -1;
	map->height = -1;
	map->player_x = -1;
	map->player_y = -1;
	map->player_side = END_OF_LINE;
	map->map = NULL;
	return (map);
}
