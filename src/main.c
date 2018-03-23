/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/23 15:59:07 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int		**g_target;
int		g_size;

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

	// TEST DEBUG
	DEBUG_display_initial_state(state->board);
	DEBUG_heuristics(state->board);
	
	a_star_search(state, manhattan_distance);
	return (0);
}