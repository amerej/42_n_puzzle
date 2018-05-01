/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 00:26:05 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:40:13 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*list_new_node(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		if (content)
		{
			node->content = ft_memalloc(content_size);
			node->content_size = content_size;
			ft_memcpy(node->content, (void *)content, content_size);
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
		node->next = NULL;
	}
	return (node);
}
