/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapp_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:04:22 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/13 19:47:59 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_heapp		*heapp_new_node(void const *data, int priority, size_t data_size)
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
