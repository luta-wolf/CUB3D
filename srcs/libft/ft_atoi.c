/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:13:42 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:13:48 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*skip(const char *str, int *z)
{
	*z = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*z = -*z;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	z;
	int	num;
	int	old_num;

	str = skip(str, &z);
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		old_num = num;
		num = num * 10 + (*str - '0') * z;
		str++;
		if ((old_num < 0 && num >= 0) || (old_num >= 0 && num < 0))
			return (2147483647);
	}
	return (num);
}
