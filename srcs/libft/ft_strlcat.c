/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:23:15 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:23:17 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	result;
	size_t	check_result;

	result = 0;
	while (dst[result] && result < dstsize)
		result++;
	check_result = result;
	while (*src && result + 1 < dstsize)
		dst[result++] = *src++;
	if (result > check_result)
		dst[result] = '\0';
	while (*src++)
		result++;
	return (result);
}
