/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:07:35 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:07:37 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	choice_side_and_set_path(const char *line, t_data *data)
{
	int		flag;
	char	*path;

	if (get_index(line, NEW_LINE) <= SIDE_LEN)
		put_error(INVALID_TEXTURE_PATH, ERR_TEX_PATH);
	path = get_subline(&line[SIDE_LEN]);
	validation_check_path(path);
	flag = check_side(line);
	if (flag == E_NORTH && data->path_north == NULL)
		data->path_north = path;
	else if (flag == E_SOUTH && data->path_south == NULL)
		data->path_south = path;
	else if (flag == E_WEST && data->path_west == NULL)
		data->path_west = path;
	else if (flag == E_EAST && data->path_east == NULL)
		data->path_east = path;
	else
		put_error(INVALID_APP_TEXTURE, ERR_TEX_APP);
}

static int	convert_texture(char *line, t_data *data)
{
	int	i;
	int	count_line;

	i = 0;
	count_line = 0;
	while (line[i] != END_OF_LINE)
	{
		while (line[i] == NEW_LINE)
			++i;
		if (count_line == TEXTURE_COUNT)
			return (i);
		choice_side_and_set_path(&line[i], data);
		++count_line;
		i += get_index(&line[i], NEW_LINE);
	}
	if (line[i] == END_OF_LINE)
		put_error(INVALID_INPUT_COUNT, ERR_COUNT_DATA);
	return (i);
}

static void	choice_side_and_set_color(char *line, t_data *data)
{
	int		i;
	char	*str;
	t_color	*color;

	color = (t_color *) malloc(sizeof (t_color));
	if (color == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	str = get_subline(&line[SURFACE_LEN]);
	color->r = up_atoi(str);
	i = get_index(str, COMMA);
	color->g = up_atoi(&str[i + 1]);
	i += get_index(&str[i + 1], COMMA) + 1;
	color->b = up_atoi(&str[i + 1]);
	i += get_index(&str[i + 1], COMMA) + 1;
	if (str[i] != END_OF_LINE)
		put_error(INVALID_COLOR_CHANNELS, ERR_COLOR_CHANNELS);
	validation_check_color(color);
	i = check_surface(line);
	if (i == E_FLOOR && data->floor == NULL)
		data->floor = color;
	else if (i == E_CEILLING && data->ceilling == NULL)
		data->ceilling = color;
	else
		put_error(INVALID_APP_COLOR, ERR_APP_COLOR);
	free(str);
}

static int	convert_color(char *line, t_data *data)
{
	int		i;
	int		color_count;

	i = 0;
	color_count = 0;
	while (line[i] != END_OF_LINE)
	{
		while (line[i] == NEW_LINE)
			++i;
		if (color_count == COLOR_COUNT)
			return (i);
		choice_side_and_set_color(&line[i], data);
		++color_count;
		i += get_index(&line[i], NEW_LINE);
	}
	if (line[i] == END_OF_LINE)
		put_error(INVALID_INPUT_COUNT, ERR_COUNT_DATA);
	return (i);
}

t_data	*convert_line_to_data(char *line)
{
	int		i;
	t_data	*data;

	if (line == NULL || line[0] == END_OF_LINE)
		put_error(INVALID_INPUT_COUNT, ERR_COUNT_DATA);
	data = create_data();
	i = convert_texture(line, data);
	i += convert_color(&line[i], data);
	data->map = convert_line_to_map(&line[i]);
	return (data);
}
