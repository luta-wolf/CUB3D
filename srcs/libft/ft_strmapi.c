/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:23:57 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:23:59 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	str_size(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	n;
	char			*str;

	if (!s)
		return ((char *)0);
	str = (char *) malloc((str_size(s) + 1) * sizeof (char));
	if (!str)
		return (str);
	i = 0;
	n = 0;
	while (s[i])
	{
		str[n] = f(i, s[i]);
		n++;
		i++;
	}
	str[n] = '\0';
	return (str);
}
