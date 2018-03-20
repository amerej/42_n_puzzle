/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 06:54:10 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/20 06:58:51 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

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

void	DEBUG_stack() {
	
	t_stack		*root = NULL;
	
	t_node_test		*node_1, *node_2, *node_3, *node_4, *node_5, *node_6;
	t_node_test		*popped;

	node_1 = (t_node_test *)malloc(sizeof(t_node_test));
	node_2 = (t_node_test *)malloc(sizeof(t_node_test));
	node_3 = (t_node_test *)malloc(sizeof(t_node_test));
	node_4 = (t_node_test *)malloc(sizeof(t_node_test));

	node_1 = &(t_node_test){1, 1};
	node_2 = &(t_node_test){2, 2};
	node_3 = &(t_node_test){3, 3};
	node_4 = &(t_node_test){4, 4};

	stack_push(&root, node_1, sizeof(t_node_test));
	stack_push(&root, node_2, sizeof(t_node_test));
	stack_push(&root, node_3, sizeof(t_node_test));
	stack_push(&root, node_4, sizeof(t_node_test));

	printf("STACK DEBUG\n\n");
	
	if((popped = stack_pop(&root)))
		printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	if((popped = stack_pop(&root)))
		printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	if((popped = stack_pop(&root)))
		printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);
}

void	DEBUG_heapp() {
	
	t_heapp		*head = NULL;
	
	t_node_test		*node_1, *node_2, *node_3, *node_4, *node_5, *node_6;
	t_node_test		*popped;

	node_1 = (t_node_test *)malloc(sizeof(t_node_test));
	node_2 = (t_node_test *)malloc(sizeof(t_node_test));
	node_3 = (t_node_test *)malloc(sizeof(t_node_test));
	node_4 = (t_node_test *)malloc(sizeof(t_node_test));
	node_5 = (t_node_test *)malloc(sizeof(t_node_test));
	node_6 = (t_node_test *)malloc(sizeof(t_node_test));

	node_1 = &(t_node_test){1, 1};
	node_2 = &(t_node_test){2, 2};
	node_3 = &(t_node_test){3, 3};
	node_4 = &(t_node_test){4, 4};
	node_5 = &(t_node_test){5, 5};
	node_6 = &(t_node_test){6, 6};

	heapp_push(&head, node_1, 4, sizeof(t_node_test));
	heapp_push(&head, node_2, 3, sizeof(t_node_test));
	heapp_push(&head, node_3, 2, sizeof(t_node_test));
	heapp_push(&head, node_4, 1, sizeof(t_node_test));
	heapp_push(&head, node_5, 2, sizeof(t_node_test));
	heapp_push(&head, node_6, 1, sizeof(t_node_test));


	printf("HEAPP DEBUG\n\n");
	if((popped = heapp_pop(&head)))
		printf("x=%d, y=%d popped from heapp\n", popped->x, popped->y);

	if((popped = heapp_pop(&head)))
		printf("x=%d, y=%d popped from heapp\n", popped->x, popped->y);

	if((popped = heapp_pop(&head)))
		printf("x=%d, y=%d popped from heapp\n", popped->x, popped->y);

	if((popped = heapp_pop(&head)))
		printf("x=%d, y=%d popped from heapp\n", popped->x, popped->y);
}