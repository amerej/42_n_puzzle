/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:56:55 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/15 02:35:42 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_stack		*stack_new_node(void const *data, size_t data_size)
{
	t_stack		*node;

	if(!(node = ft_memalloc(sizeof(t_stack))))
		return(NULL);
	if(data)
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
	return(node);
}

int			stack_is_empty(t_stack *root)
{
	return !root;
}

int			stack_push(t_stack **root, void const *data, size_t data_size)
{
	t_stack		*node;

	if(!(node = stack_new_node(data, data_size)))
		return(ERROR);
	node->next = *root;
	*root = node;
	return(SUCCESS);
}

void		*stack_pop(t_stack **root)
{
	void		*popped;
	t_stack		*tmp;

	if(stack_is_empty(*root))
		return(NULL);
	tmp = *root;
	*root = (*root)->next;
	popped = tmp->data;
	free(tmp);
	return(popped);
}

void		*stack_peek(t_stack *root)
{
	if(stack_is_empty(root))
		return(NULL);
	return root->data;
}