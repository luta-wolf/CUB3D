/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:09:00 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:09:01 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	validation_check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		put_error_and_arg(path, INVALID_FILE, ERR_FILE);
	if (close(fd) == -1)
		put_error(INVALID_CLOSE, ERR_CLOSE);
}

void	validation_check_color(t_color *color)
{
	if (color->b < 0 || color->b > 255 || color->g < 0
		|| color->g > 255 || color->r < 0 || color->r > 255)
		put_error(INVALID_COLOR, ERR_COLOR);
}
