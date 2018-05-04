/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 03:57:52 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static void		add_to_open_heapp(t_state *successors[4], t_heapp **open,
					t_btree **explored, int (*fn) (int **board, int i, int j))
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (successors[i] && !tb_explore(explored, successors[i]->board, 0, 0))
		{
			tb_add(explored, successors[i]->board, 0, 0);
			heapp_push(open, successors[i], a_star_cost(successors[i],
				heuristic(successors[i]->board, fn)), sizeof(t_state));
			free(successors[i]);
		}
		else if (successors[i])
			free_state(successors[i]);
	}
}

void			a_star_search(t_state *state,
					int (*fn) (int **board, int i, int j))
{
	t_search_var	s;

	display_initial_state(state->board, "A* SEARCH");
	s = (t_search_var) {NULL, NULL, NULL, {NULL, NULL, NULL, NULL}, 0, 1};
	tb_add(&s.explored, state->board, 0, 0);
	heapp_push(&s.open, state, a_star_cost(state,
		heuristic(state->board, fn)), sizeof(t_state));
	while (!heapp_is_empty(s.open))
	{
		s.node = heapp_pop(&s.open);
		s.t_cmplx += 1;
		if (!memcmp((*s.node->board), *g_target, g_size * g_size * sizeof(int)))
		{
			display_solution(s);
			return ;
		}
		get_successors(s.node, s.successors);
		s.s_cmplx += count_successors(s.successors);
		add_to_open_heapp(s.successors, &s.open, &s.explored, fn);
		free_state(s.node);
	}
	free_explored(&s.explored);
	if (s.open)
		free_open(&s.open);
	return ;
}
