/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:05:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 19:16:05 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		heap_push(t_heap **head, void const *data, size_t data_size)
{
	t_heap	*node;
	t_heap	*tmp;

	node = (*head);
	if (!(tmp = heap_new_node(data, data_size)))
		return (ERROR);
	if (node == NULL)
	{
		tmp->next = *head;
		(*head) = tmp;
	}
	else
	{
		while (node->next)
			node = node->next;
		tmp->next = node->next;
		node->next = tmp;
	}
	return (SUCCESS);
}
