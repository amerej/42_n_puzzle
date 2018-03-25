/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform_cost_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/25 17:15:53 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static int		uniform_cost(t_state *node)
{
	return(node->paths_size);
}

static void		add_to_open_heapp(t_state *successors[4], t_heapp **open,
					t_list **explored)
{
	int		i;

	i = -1;
	while(++i < 4)
	{
		if(successors[i] && !is_in_explored(successors[i]->board, *explored))
		{
			list_push_back(explored, successors[i]->board, 
				(g_size * g_size) * sizeof(int));
			heapp_push(open, successors[i], uniform_cost(successors[i]), 
				sizeof(t_state));
		}
	}
}

void			uniform_cost_search(t_state *state)
{
	t_list		*explored;
	t_heapp		*open;
	t_state		*node;
	t_state		*successors[4];

	explored = NULL;
	open = NULL;
	list_push_back(&explored, state->board, (g_size * g_size) * sizeof(int));
	heapp_push(&open, state, uniform_cost(state), sizeof(t_state));
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
		add_to_open_heapp(successors, &open, &explored);
	}
	return ;
}