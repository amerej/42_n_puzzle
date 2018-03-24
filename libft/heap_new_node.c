/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:04:22 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/24 06:48:02 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_heap		*heap_new_node(void const *data, size_t data_size)
{
	t_heap		*node;

	if(!(node = ft_memalloc(sizeof(t_heap))))
		return(NULL);
	if(data)
	{
		node->data = ft_memalloc(sizeof(t_heap));
		node->data_size = data_size;
		ft_memcpy(node->data, (void *)data, data_size);
	}
	else
	{
		node->data = NULL;
		node->data_size = 0;
	}
	node->next = NULL;
	return(node);
}