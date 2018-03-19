/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:51:21 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/19 07:57:46 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_heapp			*heapp_new_node(void const *data, int priority, size_t data_size)
{
	t_heapp		*node;

	if(!(node = ft_memalloc(sizeof(t_heapp))))
		return(NULL);
	if(data)
	{
		node->data = ft_memalloc(sizeof(t_heapp));
		node->priority = priority;
		node->data_size = data_size;
		ft_memcpy(node->data, (void *)data, data_size);
	}
	else
	{
		node->data = NULL;
		node->priority = 0;
		node->data_size = 0;
	}
	node->next = NULL;
	return(node);
}

int		heapp_is_empty(t_heapp *head)
{
    return !head;
}

int				heapp_push(t_heapp **head, void const *data, int priority, size_t data_size)
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

void			*heapp_pop(t_heapp **head)
{
	t_heapp		*tmp;
	void		*popped;

	if(heapp_is_empty(*head))
		return(NULL);
	
	tmp = *head;
	(*head) = (*head)->next;
	popped = tmp->data;
	free(tmp);
	return(popped);
}