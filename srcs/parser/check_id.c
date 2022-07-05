/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:06:53 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:06:54 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_side(const char *line)
{
	if (ft_strncmp(line, NORTH, SIDE_LEN) == EQUAL)
		return (E_NORTH);
	if (ft_strncmp(line, SOUTH, SIDE_LEN) == EQUAL)
		return (E_SOUTH);
	if (ft_strncmp(line, WEST, SIDE_LEN) == EQUAL)
		return (E_WEST);
	if (ft_strncmp(line, EAST, SIDE_LEN) == EQUAL)
		return (E_EAST);
	put_error(INVALID_ID_SIDE, ERR_SIDE);
	return (0);
}

int	check_surface(const char *line)
{
	if (ft_strncmp(line, FLOOR, SURFACE_LEN) == EQUAL)
		return (E_FLOOR);
	if (ft_strncmp(line, CEILLING, SURFACE_LEN) == EQUAL)
		return (E_CEILLING);
	put_error(INVALID_ID_SURFACE, ERR_ID_SURFACE);
	return (0);
}
