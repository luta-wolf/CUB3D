/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:42 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:24:44 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	char	*c;
	char	*s;

	c = (char *)str;
	s = (char *)(void *)0;
	while (*c)
	{
		if (*c == (unsigned char)a)
			s = c;
		c++;
	}
	if ((unsigned char)a == '\0')
		s = c;
	return (s);
}
