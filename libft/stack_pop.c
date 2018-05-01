/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:43:22 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:41:49 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structures.h"

void	*stack_pop(t_stack **head)
{
	void		*popped;
	t_stack		*tmp;

	if (stack_is_empty(*head))
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	popped = tmp->data;
	free(tmp);
	return (popped);
}
