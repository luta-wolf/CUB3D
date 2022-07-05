/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:16:12 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:16:19 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	len_num(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		z;

	z = (n < 0);
	size = len_num(n);
	str = (char *) malloc((size + 1) * sizeof(char));
	if (!str)
		return (str);
	if (z)
		str[0] = '-';
	str[size--] = '\0';
	while (size > (0 - !z))
	{
		str[size] = (char)(48 + (n % 10) * (!z * 2 - 1));
		n /= 10;
		size--;
	}
	return (str);
}
