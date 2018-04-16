/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/11 18:05:29 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static int		a_star_cost(t_state *node, int distance)
{
	return(node->paths_size + distance);
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
			tb_add(explored, successors[i]->board, 
				0, 0);
			heapp_push(open, successors[i], 
				a_star_cost(successors[i], heuristic(successors[i]->board, fn)), 
				sizeof(t_state));
		}
	}
}

void			a_star_search(t_state *state, int(*fn)(int **board, int i, 
					int j))
{
	t_btree		*explored;
	t_heapp		*open;
	t_state		*node;
	t_state		*successors[4];

	explored = NULL;
	open = NULL;
	tb_add(&explored, state->board, 0, 0);
	heapp_push(&open, state, a_star_cost(state, heuristic(state->board, fn)), 
		sizeof(t_state));
	while(!heapp_is_empty(open))
	{
		node = heapp_pop(&open);
		if(!memcmp((*node->board), *g_target, g_size * g_size * sizeof(int)))
		{
			printf("SOLUTION:\n\n");
			DEBUG_display_grid(node->board);
			printf("\n");
			printf("OPEN LIST: %d\n\n", heapp_size(open));
			printf("CLOSED LIST: %d\n\n", ft_list_size(explored));
			printf("PATHS:\n\n");
			print_paths(node);
			printf("\n");
			return ;
		}
		get_successors(node, successors);
		add_to_open_heapp(successors, &open, &explored, fn);
	}
	return ; // To implement
}
