/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:14:44 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:14:51 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *) malloc(count * size);
	if (!str)
		return (str);
	i = 0;
	while (i < count * size)
		str[i++] = '\0';
	return ((void *) str);
}
