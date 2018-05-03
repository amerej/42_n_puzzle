/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform_cost_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/02 23:09:02 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static int		uniform_cost(t_state *node)
{
	return (node->paths_size);
}

static void		add_to_open_heapp(t_state *successors[4], t_heapp **open,
					t_btree **explored)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (successors[i] && !tb_explore(explored, successors[i]->board, 0, 0))
		{
			tb_add(explored, successors[i]->board, 0, 0);
			heapp_push(open, successors[i],
				uniform_cost(successors[i]), sizeof(t_state));
			free(successors[i]);
		}
		else if (successors[i])
			free_state(successors[i]);
	}
}

void			uniform_cost_search(t_state *state)
{
	printf("IN uniform\n");
	t_btree		*explored;
	t_heapp		*open;
	t_state		*node;
	t_state		*successors[4];

	explored = NULL;
	open = NULL;
	tb_add(&explored, state->board, 0, 0);
	heapp_push(&open, state, uniform_cost(state), sizeof(t_state));
	while (!heapp_is_empty(open))
	{
		node = heapp_pop(&open);
		if (!memcmp((*node->board), *g_target, g_size * g_size * sizeof(int)))
		{
			printf("SOLUTION UNIFORM COST SEARCH\n\n");
			display_grid(node->board);
			printf("\n");
			printf("OPEN LIST: %d\n\n", heapp_size(open));
			// printf("CLOSED LIST: %d\n\n", ft_list_size(explored));
			printf("PATHS:\n\n");
			display_paths(node);
			printf("\n");
			free_state(node);
			free_explored(&explored);
			if (open)
				free_open(&open);
			return ;
		}
		get_successors(node, successors);
		add_to_open_heapp(successors, &open, &explored);
		free_state(node);
	}
	free_explored(&explored);
	if (open)
		free_open(&open);
	return ;
}
