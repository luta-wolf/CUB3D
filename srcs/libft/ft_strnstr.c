/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:24 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:24:26 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*str2 == '\0' || str1 == str2 || (len == 1 && *str1 == *str2))
		return ((char *)str1);
	while (str1[i] && len--)
	{
		j = 0;
		while (str1[i + j] && len >= j && str1[i + j] == str2[j])
			j++;
		if (str2[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return ((char *)0);
}
