/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:57:29 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/23 10:17:18 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static void		copy_board(int **dst_board, int **src_board)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while(++j < g_size)
			dst_board[i][j] = src_board[i][j];
	}
}

int				board_cmp(int **a, int **b)
{
	int		i;
	int		j;

	i = -1;
	while(++i < g_size)
	{
		j = -1;
		while(++j < g_size)
			if(a[i][j] != b[i][j])
				return(FALSE);
	}
	return(TRUE);
}

int				is_in_explored(int **board, t_list *explored)
{
	while(explored)
	{
		if(board_cmp(board, explored->content))
			return(TRUE);
		explored = explored->next;
	}
	return(FALSE);
}

t_state			*generate_move(t_state *state, t_position pos)
{
	int			n;
	t_state		*new_state;

	new_state = init_state();
	new_state->board = init_grid();
	copy_board(new_state->board, state->board);
	while(state->paths)
	{
		list_push_back(&new_state->paths, state->paths->content, sizeof(t_position));
		state->paths = state->paths->next;
	}
	n = state->board[state->empty.i + pos.i][state->empty.j + pos.j];
	new_state->board[state->empty.i][state->empty.j] = n;
	new_state->board[state->empty.i + pos.i][state->empty.j + pos.j] = 0;
	new_state->empty = (t_position){state->empty.i + pos.i, state->empty.j + pos.j};
	list_push_back(&new_state->paths, &pos, sizeof(t_position));
	return(new_state);
}

void			get_successors(t_state *state, t_state *successors[])
{
	successors[0] = NULL;
	successors[1] = NULL;
	successors[2] = NULL;
	successors[3] = NULL;
	
	if(state->empty.j - 1 >= 0)
		successors[0] = generate_move(state, (t_position){0, -1});
	if(state->empty.i - 1 >= 0)
		successors[1] = generate_move(state, (t_position){-1, 0});
	if(state->empty.i + 1 < g_size)
		successors[2] = generate_move(state, (t_position){1, 0});
	if(state->empty.j + 1 < g_size)
		successors[3] = generate_move(state, (t_position){0, 1});
}