/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:16:33 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 00:14:37 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		hamming_distance(t_node *node)
{
	
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
