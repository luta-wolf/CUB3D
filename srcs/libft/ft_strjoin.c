/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:23:02 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:23:04 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char *) malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (str);
	j = -1;
	i = -1;
	while (s1[++j])
		str[j] = s1[j];
	while (s2[++i])
		str[i + j] = s2[i];
	str[i + j] = '\0';
	return (str);
}
