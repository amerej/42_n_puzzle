/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:16:33 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 00:14:01 by aditsch          ###   ########.fr       */
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

int		euclidean_distance(t_node *node)
{
	
}