/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapp_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:05:41 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:28:12 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*heapp_pop(t_heapp **head)
{
	t_heapp		*tmp;
	void		*popped;

	if (heapp_is_empty(*head))
		return (NULL);
	tmp = *head;
	(*head) = (*head)->next;
	popped = tmp->data;
	free(tmp);
	return (popped);
}
