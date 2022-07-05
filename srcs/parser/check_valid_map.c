/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:07:17 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:07:19 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	check_element(char **arr, int i, int k)
{
	if (i == 0 || arr[i - 1][k] == SPACE)
		put_error(INVALID_MAP, ERR_MAP);
	if (arr[i + 1] == NULL || arr[i + 1][k] == SPACE)
		put_error(INVALID_MAP, ERR_MAP);
	if (k == 0 || arr[i][k - 1] == SPACE)
		put_error(INVALID_MAP, ERR_MAP);
	if (arr[i][k + 1] == SPACE || arr[i][k + 1] == END_OF_LINE)
		put_error(INVALID_MAP, ERR_MAP);
}

void	check_valid_map(t_map *map)
{
	int		i;
	int		k;
	char	**arr;

	if (map->player_x == -1)
		put_error(INVALID_PLAYER, ERR_PLAYER);
	i = -1;
	arr = map->map;
	while (arr[++i] != NULL)
	{
		k = -1;
		while (arr[i][++k] == SPACE || arr[i][k] == BLOCK
			|| arr[i][k] == EMPTY || arr[i][k] == map->player_side)
		{
			if (arr[i][k] == EMPTY || arr[i][k] == map->player_side)
				check_element(arr, i, k);
		}
		if (arr[i][k] != END_OF_LINE)
			put_error(INVALID_SYMBOL, ERR_SYMBOL);
	}
}
