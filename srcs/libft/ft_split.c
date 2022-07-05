/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:22:14 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:22:17 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_mass_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i + 1);
}

static int	get_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len + 1);
}

static char	**clear(char **mass)
{
	int	i;

	i = -1;
	while (mass[++i])
		free(mass[i]);
	free(mass);
	return (NULL);
}

static int	add_word(char *word, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (i);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		k;
	char	**words;

	if (!s)
		return (NULL);
	words = (char **) malloc(get_mass_size(s, c) * sizeof(char *));
	if (words == (NULL))
		return (words);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			words[k] = (char *)malloc(get_len(&s[i], c) * sizeof(char));
			if (words[k] == (char *)(void *)0)
				return (clear(words));
			i += add_word(words[k++], &s[i], c);
		}
	}
	words[k] = (char *)(void *)0;
	return (words);
}
