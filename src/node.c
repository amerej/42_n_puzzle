/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:42:37 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 06:32:46 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int 			make_goal(t_node *node, int size)
{
	int		ts = size * size;
	int		cur = 1;
	int		x = 0;
	int		ix = 1;
	int		y = 0;
	int		iy = 0;

	if (!(node->goal = init_grid(size))) {
		printf("error: init_goal");
		return (0);
	}
	while(1) {
		(*node->goal)[x + y * size] = cur;
		if (!cur)
			break;
		cur++;
		if (x + ix == size || x + ix < 0 || (ix != 0 && (*node->goal)[x + ix + y*size] != -1)) {
			iy = ix;
			ix = 0;
		}
		else if (y + iy == size || y + iy < 0 || (iy != 0 && (*node->goal)[x + (y+iy)*size] != -1)) {
			ix = -iy;
			iy = 0;
		}
		x += ix;
		y += iy;
		if (cur == size * size)
			cur = 0;
	}
	return (1);
}

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
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			grid[i][j] = -1;
		}
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