/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:07:29 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:07:31 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	get_size_line(const char *line)
{
	int	i;
	int	stop;
	int	max_len;

	if (*line == END_OF_LINE)
		put_error(INVALID_NO_MAP, ERR_EMPTY_MAP);
	i = 0;
	stop = 0;
	max_len = 0;
	while (line[i] != END_OF_LINE)
	{
		while (line[i] != END_OF_LINE && line[i] != NEW_LINE)
			++i;
		if (i - stop > max_len)
			max_len = i - stop;
		stop = ++i;
	}
	return (max_len);
}

static int	get_count_line(const char *line)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (line[++i])
		if (line[i] == NEW_LINE)
			++count;
	return (count);
}

static char	**get_map(char *line, int line_count, int line_size)
{
	int		i;
	int		k;
	char	*str;
	char	**arr;

	arr = (char **) malloc(sizeof (char *) * (line_count + 1));
	if (arr == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	k = 0;
	while (*line != END_OF_LINE && k < line_count)
	{
		str = (char *) malloc(sizeof (char) * (line_size + 1));
		if (str == NULL)
			put_error(INVALID_MEMORY, ERR_MEMORY);
		i = 0;
		while (*line != END_OF_LINE && *line != NEW_LINE)
			str[i++] = *(line++);
		while (i < line_size)
			str[i++] = SPACE;
		str[i] = END_OF_LINE;
		++line;
		arr[k++] = str;
	}
	arr[k] = NULL;
	return (arr);
}

static void	init_player_data(t_map *map)
{
	int		i;
	int		k;
	int		flag;
	char	**arr;

	i = -1;
	flag = FALSE;
	arr = map->map;
	while (arr[++i] != NULL)
	{
		k = -1;
		while (arr[i][++k] != END_OF_LINE)
		{
			if (arr[i][k] == SIDE_N || arr[i][k] == SIDE_S
				|| arr[i][k] == SIDE_W || arr[i][k] == SIDE_E)
			{
				if (flag == TRUE)
					put_error(INVALID_MULTIPLAYER, ERR_MULTIPLAYER);
				flag = TRUE;
				map->player_x = k;
				map->player_y = i;
				map->player_side = arr[i][k];
			}
		}
	}
}

t_map	*convert_line_to_map(char *line)
{
	t_map	*map;

	map = create_map();
	map->width = get_size_line(line);
	map->height = get_count_line(line);
	if (map->width < MIN_WIDTH || map->height < MIN_HEIGHT)
		put_error(INVALID_NO_MAP, ERR_EMPTY_MAP);
	map->map = get_map(line, map->height, map->width);
	init_player_data(map);
	check_valid_map(map);
	return (map);
}
