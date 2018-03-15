/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:42:37 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/15 22:19:09 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int		**alloc_grid(int size)
{
	int		**grid;

	if(!(grid = (int **)malloc(sizeof(int *) * size)))
	{
		perror("error : grid memory allocation");
		return(NULL);
	}
	if(!(grid[0] = (int *)malloc(sizeof(int) * size * size)))
	{
		perror("error : grid memory allocation");
		return(NULL);
	}
	return(grid);
}

int				**init_grid(int size)
{
	int		**grid;
	int		i;
	int		j;

	if (!(grid = alloc_grid(size)))
		return(NULL);
	i = 0;
	while(i < size) {
		grid[i] = (*grid + size * i);
		i++;
	}
	i = 0;
	while(i < size) {
		j = 0;
		while(j < size) {
			grid[i][j] = -1;
			j++;
		}
		i++;
	}
	return (grid);
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
	node->goal = NULL;
	node->n = 0;
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