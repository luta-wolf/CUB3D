/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_subline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:08:15 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:08:17 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*get_subline(const char *line)
{
	int		i;
	char	*subline;

	while (*line == SPACE)
		++line;
	if (*line == END_OF_LINE)
		put_error(INVALID_LINE, ERR_LINE);
	i = 0;
	while (line[i] != END_OF_LINE && line[i] != NEW_LINE)
		++i;
	subline = ft_substr(line, 0, i);
	if (subline == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	return (subline);
}
