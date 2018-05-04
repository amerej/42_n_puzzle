/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 06:54:10 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 06:19:55 by aditsch          ###   ########.fr       */
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
			printf("%3d ", grid[i][j]);
		printf("\n");
	}
}

void		display_initial_state(int **board, char *algo)
{
	printf("\n%s\n\n", algo);
	printf("INITIAL STATE:\n\n");
	display_grid(board);
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
	int				i;
	int				n;
	t_position		empty;

	i = -1;
	display_grid(g_initial);
	printf("\n");
	while (++i < state->paths_size)
	{
		empty = get_empty(g_initial);
		n = g_initial[empty.i + state->paths[i].i][empty.j + state->paths[i].j];
		g_initial[empty.i][empty.j] = n;
		g_initial[empty.i + state->paths[i].i][empty.j + state->paths[i].j] = 0;
		display_grid(g_initial);
		printf("\n");
	}
}

void		display_solution(t_search_var s)
{
	printf("FINAL STATE:\n\n");
	display_grid(s.node->board);
	printf("\n");
	printf("SIZE COMPLEXITY: %d\n\n", s.s_cmplx);
	printf("TIME COMPLEXITY: %d\n\n", s.t_cmplx);
	printf("NUMBER OF MOVES: %d\n\n", s.node->paths_size);
	printf("MOVES:\n\n");
	display_paths(s.node);
	printf("\n");
	free_state(s.node);
	free_explored(&s.explored);
	if (s.open)
		free_open(&s.open);
}
