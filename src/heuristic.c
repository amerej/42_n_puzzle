/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:16:33 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 00:17:40 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static t_position		get_position(int **goal, int size, int n)
{
	int				i;
	int				j;
	t_position		pos;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			printf("%d ", goal[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int				hamming_distance(t_node *node)
{
	int				i;
	int				j;
	int				res;

	i = 0;
	res = 0;
	while(i < node->n)
	{
		j = 0;
		while(j < node->n)
		{
			if (node->grid[i][j] != 0 && node->grid[i][j] != node->goal[i][j])
				res++;
			j++;
		}
		i++;
	}
	printf("hamming_distance= %d\n", res);
	return(res);
}

int		manhattan_distance(t_node *node)
{

}

int search_distance(node, grid_y, grid_x, number)
{
	int		dist_x;
	int		dist_y;
	int		goal_y;
	int		goal_x;
	int distance;

	goal_y = -1;
	goal_x = -1;
	distance = 0
	while (++goal_y < node->n)
	{
		goal_x = -1;
		while (++goal_x < node->n)
			if (node->grid[grid_y][grid_x] == node->goal[goal_y][goal_x])
			{
				dist_y = grid_y - goal_y;
				dist_x = grid_x - goal_y;
				distance = sqrt(dist_y * dist_y + dist_x * dist_x)
				break;
			}
	}
	return (ceil(distance));
}

int		euclidean_distance(t_node *node)
{
	int		y;
	int		x;
	int 	result;

	y = -1;
	x = -1;
	result = 0;
	while (++y < node->n)
	{
		x = -1;
		while (++x < node->n)
		{
			if (node->grid[y][x] != 0 && node->grid[y][x] != node->goal[y][x])
				result += search_distance(node, y, x, node->grid[y][x])
		}
	}
	return (result)
}
