/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:08:25 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:08:27 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_data	*parse(int argc, char **argv)
{
	char	*str;
	t_data	*data;

	if (argc != 2)
		put_error(INVALID_ARG_COUNT, ERR_ARG);
	str = read_file(argv[1]);
	data = convert_line_to_data(str);
	free(str);
	return (data);
}
