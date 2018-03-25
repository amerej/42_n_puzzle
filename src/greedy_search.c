/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/25 11:59:00 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static int		greedy_cost(t_state *node, int distance)
{
	return(distance);
}

static void		add_to_open_heapp(t_state *successors[4], t_heapp **open,
					t_list **explored, int(*fn)(int **board, int i, int j))
{
	int		i;

	i = -1;
	while(++i < 4)
	{
		if(successors[i] && !is_in_explored(successors[i]->board, *explored))
		{
			list_push_back(explored, successors[i]->board, 
				(g_size * g_size) * sizeof(int));
			heapp_push(open, successors[i], 
				greedy_cost(successors[i], heuristic(successors[i]->board, fn)), 
				sizeof(t_state));
		}
	}
}

void			greedy_search(t_state *state, int(*fn)(int **board, int i, 
					int j))
{
	t_list		*explored;
	t_heapp		*open;
	t_state		*node;
	t_state		*successors[4];

	explored = NULL;
	open = NULL;
	list_push_back(&explored, state->board, (g_size * g_size) * sizeof(int));
	heapp_push(&open, state, greedy_cost(state, heuristic(state->board, fn)), 
		sizeof(t_state));
	while(!heapp_is_empty(open))
	{
		node = heapp_pop(&open);
		if(!memcmp((*node->board), *g_target, g_size * g_size * sizeof(int)))
		{
			printf("SOLUTION\n\n");
			DEBUG_display_grid(node->board);
			printf("\n");
			print_paths(node);
			return ;
		}
		get_successors(node, successors);
		add_to_open_heapp(successors, &open, &explored, fn);
	}
	return ;
}