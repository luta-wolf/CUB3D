/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:21:43 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:21:46 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	rec(int n, int fd)
{
	char	c;

	if (n > 9 || n < -9)
		rec(n / 10, fd);
	c = (char)(((n % 10) * ((n > 0) * 2 - 1)) + '0');
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	rec(n, fd);
}
