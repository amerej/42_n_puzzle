/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapp_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:24:23 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:29:20 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		heapp_size(t_heapp *head)
{
	int		count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
