/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/15 02:38:15 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int main(int argc, char *argv[])
{
	t_node		*node;

	node = NULL;
	if (!(check_arguments(argc)))
		return (-1);
	if (!(node = new_node()))
		return (-1);
	if (!(get_puzzle(node, argv[1])))
		return (-1);
	// TEST AFFICHAGE
	// printf("n: %d\n", node->n);
	// printf("puzzle:\n");
	// for (int i = 0; i < node->n; i++) {
	// 	for (int j = 0; j < node->n; j++) {
	// 		printf("%d ", node->board[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("goal:\n");
	// for (int i = 0; i < node->n; i++) {
	// 	for (int j = 0; j < node->n; j++) {
	// 		printf("%d ", node->goal[i][j]);
	// 	}
	// 	printf("\n");
	// }

	// TEST STACK
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
	
	return (0);
}