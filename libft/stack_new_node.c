/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:42:15 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:42:01 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structures.h"

t_stack		*stack_new_node(void const *data, size_t data_size)
{
	t_stack		*node;

	if (!(node = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	if (data)
	{
		node->data = ft_memalloc(data_size);
		node->data_size = data_size;
		ft_memcpy(node->data, (void *)data, data_size);
	}
	else
	{
		node->data = NULL;
		node->data_size = 0;
	}
	node->next = NULL;
	return (node);
}
