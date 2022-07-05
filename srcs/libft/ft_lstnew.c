/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:19:41 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:19:43 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_element;

	new_element = (t_list *) malloc(sizeof(t_list));
	if (!new_element)
		return (new_element);
	new_element->value = content;
	new_element->pot = 0;
	new_element->bool = 0;
	new_element->lst_size = 1;
	new_element->sort_lst = NULL;
	new_element->next = NULL;
	new_element->back = NULL;
	return (new_element);
}
