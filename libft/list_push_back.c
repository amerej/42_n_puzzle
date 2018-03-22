/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 00:04:43 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/22 00:33:01 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		list_push_back(t_list **head, void const *data, size_t data_size)
{
	t_list	*list;
	t_list	*node;

	if(!(node = list_new_node(data, data_size)))
		return(ERROR);
	list = *head;
	if (!list)
	{
		list = node;
		*head = list;
	}
	else
	{
		while(list->next)
			list = list->next;
		list->next = node;
	}
	return(SUCCESS);
}