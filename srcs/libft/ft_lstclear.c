/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:17:13 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:17:18 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*buff;

	while (*lst)
	{
		buff = (*lst)->next;
		free(*lst);
		(*lst) = buff;
	}
	*lst = NULL;
}
