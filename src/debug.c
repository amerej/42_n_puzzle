/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 06:54:10 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/30 23:09:34 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

void	DEBUG_display_grid(int **grid) {
	
	for (int i = 0; i < g_size; i++) {
		for (int j = 0; j < g_size; j++) {
			printf("%3d ", grid[i][j]);
		}
		printf("\n");
	}
}

void	DEBUG_display_initial_state(int **board) {
	
	printf("\nPUZZLE INFORMATIONS\n\n");	
	printf("Initial State\n");
	DEBUG_display_grid(board);
	printf("\nGoal State\n");
	DEBUG_display_grid(g_target);
	printf("\n");
}

void	DEBUG_heuristics(int **board) {
	
	printf("HEURISTICS\n\n");
	printf("Hamming: %d\n", heuristic(board, hamming_distance));
	printf("Manhattan: %d\n", heuristic(board, manhattan_distance));
	printf("Euclidean: %d\n", heuristic(board, euclidean_distance));
	printf("\n");
}

void	printList(t_list *n)
{
	while (n != NULL)
	{
		DEBUG_display_grid(n->content);
		printf("\n");
		n = n->next;
	}
}
