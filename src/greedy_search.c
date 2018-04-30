/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/30 23:29:52 by nrouzeva         ###   ########.fr       */
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
		if(successors[i] && !tb_explore(explored, successors[i]->board, 0, 0))
		{
			tb_add(explored, successors[i]->board, 0, 0);
			heapp_push(open, successors[i], greedy_cost(successors[i], 
				heuristic(successors[i]->board, fn)), 
				sizeof(t_state));
		}
		else if (successors[i])
		{
			free(successors[i]->paths);
			free(successors[i]->board[0]);
			free(successors[i]->board);
			free(successors[i]);
		}
	}
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
	heapp_push(&open, state, 
		greedy_cost(state, heuristic(state->board, fn)), sizeof(t_state));
	while(!heapp_is_empty(open))
	{
		node = heapp_pop(&open);
		if(!memcmp((*node->board), *g_target, g_size * g_size * sizeof(int)))
		{
			printf("SOLUTION:\n\n");
			DEBUG_display_grid(node->board);
			printf("\n");
			printf("OPEN LIST: %d\n\n", heapp_size(open));
			printf("PATHS:\n\n");
			print_paths(node);
			printf("\n");
			free_state(node);
			free_explored(&explored);
			if(open)
				free_open(&open);
			return ;
		}
		get_successors(node, successors);
		add_to_open_heapp(successors, &open, &explored, fn);
		free_state(node);
	}
	free_explored(&explored);
	if(open)
		free_open(&open);
	return ;
}
