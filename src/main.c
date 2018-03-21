/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/21 05:07:03 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int			**g_target;
int			g_size;

int main(int argc, char *argv[])
{
	t_state		*state;

	state = NULL;
	if (!(check_arguments(argc)))
		return (-1);
	if (!(state = new_state()))
		return (-1);
	if (!(get_initial_state(state, argv[1])))
		return (-1);
	init_target();

	//TEST DEBUG
	DEBUG_display_initial_state(state->board);
	DEBUG_heuristics(state->board);

	//TEST SUCCESSORS
	// t_state *successors[4];

	// get_successors(state, successors);
	// if (successors[0])
	// {
	// 	printf("Successor 1\n");
	// 	DEBUG_display_grid(successors[0]->board);
	// }
	// if (successors[1])
	// {
	// 	printf("Successor 2\n");
	// 	DEBUG_display_grid(successors[1]->board);
	// }
	// if (successors[2])
	// {
	// 	printf("Successor 3\n");
	// 	DEBUG_display_grid(successors[2]->board);
	// }
	// if (successors[3])
	// {
	// 	printf("Successor 4\n");
	// 	DEBUG_display_grid(successors[3]->board);
	// }

	// TEST STACK
	// DEBUG_stack();

	// TEST HEAPP
	// DEBUG_heapp();

	return (0);
}

t_state		*generate_move(t_state *state, int i, int j)
{
	int			n;
	t_state		*new_state;

	new_state = init_state();
	new_state->board = init_grid();
	copy_board(new_state->board, state->board);

	n = state->board[state->empty.i + i][state->empty.j + j];
	new_state->board[state->empty.i][state->empty.j] = n;
	new_state->board[state->empty.i + i][state->empty.j + j] = 0;
	new_state->empty = (t_position){state->empty.i + i, state->empty.j + j};
	new_state->path = state->path + 1;
	return(new_state);
}

void		get_successors(t_state *state, t_state *successors[])
{
	ft_memset(successors, 0, 4);
	if(state->empty.j - 1 >= 0)
		successors[0] = generate_move(state, 0, -1);
	if(state->empty.i - 1 >= 0)
		successors[1] = generate_move(state, -1, 0);
	if(state->empty.i + 1 <= g_size)
		successors[2] = generate_move(state, 1, 0);
	if(state->empty.j + 1 <= g_size)
		successors[3] = generate_move(state, 0, 1);
}