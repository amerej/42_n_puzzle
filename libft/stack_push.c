/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:43:26 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/19 19:36:13 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structures.h"

int		stack_push(t_stack **head, void const *data, size_t data_size)
{
	t_stack		*node;

	if(!(node = stack_new_node(data, data_size)))
		return(ERROR);
	node->next = *head;
	*head = node;
	return(SUCCESS);
}