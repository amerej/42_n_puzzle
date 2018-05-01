/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:05:41 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:25:49 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*heap_pop(t_heap **head)
{
	t_heap	*tmp;
	void	*popped;

	if (heap_is_empty(*head))
		return (NULL);
	tmp = *head;
	(*head) = (*head)->next;
	popped = tmp->data;
	free(tmp);
	return (popped);
}
