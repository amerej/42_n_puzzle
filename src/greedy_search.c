/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/14 14:08:02 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static int		greedy_cost(t_state *node, int distance)
{
	return(distance);
}

static void		add_to_open_heapp(t_state *successors[4], t_heapp **open,
					t_btree **explored, int(*fn)(int **board, int i, int j))
{
	int		i;

	i = -1;
	while(++i < 4)
	{
		if(successors[i] && !tb_explore(explored, successors[i]->board,  0, 0))
		{
//			printf("%d, %d\n", successors[i]->empty.j, successors[i]->empty.i);
			tb_add(explored, successors[i]->board, 0, 0);
			heapp_push(open, successors[i], greedy_cost(successors[i], 
				heuristic(successors[i]->board, fn)), 
				sizeof(t_state));
		}
	}
}

void		print_heap(t_heapp **open)
{
	t_heapp *node = (*open);
	t_state *state = (*open)->data;
	printf("PRIORITY = %d\n", node->priority);
	printf("%d, %d\n", state->empty.j, state->empty.i);
	if (node->next)
		print_heap(&node->next);
}


void			greedy_search(t_state *state, int(*fn)(int **board, int i, 
					int j))
{
	t_btree		*explored;
	t_heapp		*open;
	t_state		*node;
	t_state		*successors[4];
	int ok = 0;

	explored = NULL;
	open = NULL;
	tb_add(&explored, state->board, 0, 0);
	heapp_push(&open, state, greedy_cost(state, heuristic(state->board, fn)), sizeof(t_state));
	while(!heapp_is_empty(open))
	{
//		printf("%d\n", ++ok);
		node = heapp_pop(&open);
//		printf("%d, %d\n", node->empty.j, node->empty.i);
		if(!memcmp((*node->board), *g_target, g_size * g_size * sizeof(int)))
		{
			printf("SOLUTION:\n\n");
			DEBUG_display_grid(node->board);
			printf("\n");
			printf("OPEN LIST: %d\n\n", heapp_size(open));
//			printf("PATHS:\n\n");
//			print_paths(node);
			printf("\n");
			return ;
		}
		get_successors(node, successors);
		add_to_open_heapp(successors, &open, &explored, fn);
//		print_heap(&open);
//		DEBUG_display_grid(node->board);
//		printf("\n");
//		sleep(5);
	}
	return ;
}
