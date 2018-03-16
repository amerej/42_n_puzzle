#include "npuzzle.h"

void	DEBUG_display_grid(t_type **grid, t_type size) {
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%3d ", grid[i][j]);
		}
		printf("\n");
	}
}

void	DEBUG_display_initial_state(t_puzzle *puzzle) {
	
	printf("\nPUZZLE INFORMATIONS\n\n");	
	printf("Initial State\n");
	DEBUG_display_grid(puzzle->board, puzzle->size);
	printf("\nGoal State\n");
	DEBUG_display_grid(puzzle->goal, puzzle->size);
	printf("\n");
}

void	DEBUG_heuristics(t_puzzle *puzzle) {
	
	printf("HEURISTICS\n\n");
	printf("Hamming: %d\n", hamming_distance(puzzle));
	printf("Manhattan: %d\n", manhattan_distance(puzzle));
	printf("Euclidean: %d\n", euclidean_distance(puzzle));
	printf("\n");
}

void	DEBUG_stack() {
	
	t_stack		*root = NULL;
	
	t_node_test		*node_1;
	t_node_test		*node_2;
	t_node_test		*node_3;
	t_node_test		*node_4;
	t_node_test		*popped;
	t_node_test		*top;

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
	popped = stack_pop(&root);
	printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	popped = stack_pop(&root);
	printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	// popped = stack_pop(&root);
	// printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	// popped = stack_pop(&root);
	// printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	popped = stack_pop(&root);
	if (popped)
		printf("x=%d, y=%d popped from stack\n", popped->x, popped->y);

	top = stack_peek(root);
	if (top)
		printf("Top element is x=%d, y=%d\n", top->x, top->y);
}