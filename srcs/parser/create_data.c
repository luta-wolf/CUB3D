/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:07:47 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:07:49 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_data	*create_data(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof (t_data));
	if (data == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	data->path_north = NULL;
	data->path_south = NULL;
	data->path_west = NULL;
	data->path_east = NULL;
	data->floor = NULL;
	data->ceilling = NULL;
	return (data);
}
