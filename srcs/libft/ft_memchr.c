/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:19:58 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:20:04 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int s, size_t n)
{
	void	*result;

	result = (void *)0;
	while (n > 0)
	{
		if (*(char *)str == (char)s)
		{
			result = (void *)str;
			break ;
		}
		str++;
		n--;
	}
	return (result);
}
