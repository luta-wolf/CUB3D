/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:54 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:24:57 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	checker(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*get_str(char const *s1, unsigned int size)
{
	char			*str;
	unsigned int	j;

	str = (char *) malloc((size + 1) * sizeof (char));
	if (!str)
		return (str);
	j = 0;
	while (j < size)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	i;
	unsigned int	size;

	size = 0;
	i = 0;
	if (!s1)
		return ((char *)s1);
	while ((s1[i]) && (checker(s1[i], set)))
		i++;
	while ((s1[i + size]) && (s1[i + size + 1]))
		size++;
	while (checker(s1[i + size], set))
		size--;
	return (get_str(&s1[i], ++size));
}
