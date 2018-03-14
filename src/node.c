/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:42:37 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 04:19:11 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int				**init_grid(int size)
{
	int		**grid, i, j;

	if (!(grid = (int **)malloc(sizeof(int *) * size)))
	{
		perror("error : grid memory allocation");
		return (NULL);
	}
	if (!(grid[0] = (int *)malloc(sizeof(int) * size * size)))
	{
		perror("error : grid memory allocation");
		return (NULL);
	}
	for(i = 0; i < size; i++) {
		grid[i] = (*grid + size * i);
	}
	return grid;
}

static t_node	*init_node(void)
{
	t_node		*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
	{
		perror("error : node memory allocation");
		return (NULL);
	}
	node->grid = NULL;
	node->parent = NULL;
	return (node);
}

t_node			*new_node(void)
{
	t_node		*node;
	int			flag;

	flag = 0;
	if (!(node = init_node()))
		flag = 1;
	if (flag)
	{
		ft_putstr_fd("error : setting node\n", 2);
		destroy_node(node);
		return (NULL);
	}
	return (node);
}

void			destroy_node(t_node *node)
{
	ft_free_ptr((void **)&node);
}