/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 06:54:10 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/03 23:48:27 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

void		display_grid(int **grid)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			printf("%3d ", grid[i][j]);
		}
		printf("\n");
	}
}

void		display_initial_state(int **board)
{
	printf("\nPUZZLE INFORMATIONS\n\n");
	printf("Initial State\n");
	display_grid(board);
	printf("\nGoal State\n");
	display_grid(g_target);
	printf("\n");
}

void		display_heuristics(int **board)
{
	printf("HEURISTICS\n\n");
	printf("Hamming: %d\n", heuristic(board, hamming_distance));
	printf("Manhattan: %d\n", heuristic(board, manhattan_distance));
	printf("Euclidean: %d\n", heuristic(board, euclidean_distance));
	printf("\n");
}

void		display_paths(t_state *state)
{
	int		i;

	i = -1;
	while (++i < state->paths_size)
		printf("{%d,%d} ", state->paths[i].i, state->paths[i].j);
	printf("\n");
}
