/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapp_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:05:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/30 23:20:03 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		heapp_push(t_heapp **head, void const *data, int priority, size_t data_size)
{
	t_heapp		*node;
	t_heapp		*tmp;

	node = (*head);
	if(!(tmp = heapp_new_node(data, priority, data_size)))
		return(ERROR);
	
	if((node == NULL || node->priority > priority))
	{
		tmp->next = *head;
		(*head) = tmp;
	}
	else
	{
		while(node->next && node->next->priority < priority)
			node = node->next;
		tmp->next = node->next;
		node->next = tmp;
	}
	return(SUCCESS);
}
