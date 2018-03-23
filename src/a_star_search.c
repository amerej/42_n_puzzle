/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/23 10:31:42 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static int		a_star_cost(t_state *node, int distance)
{
	return(ft_list_size(node->paths) + distance);
}

void			a_star_search(t_state *state, int(*fn)(int **board, int i, int j))
{
	t_list		*explored;
	t_heapp		*open;
	t_state		*node;
	t_state		*successors[4];
	int			i;

	explored = NULL;
	open = NULL;
	list_push_back(&explored, state->board, (g_size * g_size) * sizeof(int));
	heapp_push(&open, state, a_star_cost(state, heuristic(state->board, fn)), sizeof(t_state));
	while(!heapp_is_empty(open))
	{
		node = heapp_pop(&open);
		if(board_cmp(node->board, g_target))
		{
			// To implement
			DEBUG_display_grid(node->board);
			printf("SUCCESS!\n");
			return ;
		}
		get_successors(node, successors);
		i = -1;
		while(++i < 4)
		{
			if(successors[i] && !is_in_explored(successors[i]->board, explored))
			{
				list_push_back(&explored, successors[i]->board, (g_size * g_size) * sizeof(int));
				// DEBUG_display_grid(successors[i]->board);
				// printf("\n");
				heapp_push(&open, successors[i], a_star_cost(successors[i], heuristic(successors[i]->board, fn)), sizeof(t_state));
			}
		}
	}
	return ; // To implement
}
