/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:22:35 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:22:37 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (str);
	while (i > 0)
	{
		str[i] = s1[i];
		i--;
	}
	str[i] = s1[i];
	return (str);
}
