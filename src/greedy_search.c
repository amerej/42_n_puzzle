/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:05:30 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 06:36:44 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static void		add_to_open_heapp(t_state *successors[4], t_heapp **open,
					t_btree **explored, t_heuristic h)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (successors[i] && !tb_explore(explored, successors[i]->board, 0, 0))
		{
			tb_add(explored, successors[i]->board, 0, 0);
			heapp_push(open, successors[i], greedy_cost(
				heuristic(successors[i]->board, h)), sizeof(t_state));
			free(successors[i]);
		}
		else if (successors[i])
			free_state(successors[i]);
	}
}

void			greedy_search(t_state *state, t_heuristic h)
{
	t_search_var	s;

	display_initial_state(state->board, "GREEDY SEARCH");
	s = (t_search_var) {NULL, NULL, NULL, {NULL, NULL, NULL, NULL}, 0, 1};
	tb_add(&s.explored, state->board, 0, 0);
	heapp_push(&s.open, state,
		greedy_cost(heuristic(state->board, h)), sizeof(t_state));
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
		add_to_open_heapp(s.successors, &s.open, &s.explored, h);
		free_state(s.node);
	}
	free_explored(&s.explored);
	free_open(&s.open);
	printf("\nNO SOLUTION\n\n");
	return ;
}
