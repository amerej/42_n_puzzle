/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:28:19 by nrouzeva          #+#    #+#             */
/*   Updated: 2018/05/02 23:11:05 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int		command_line_parser(t_state *state, int argc, char **argv)
{
	int (*f)(int **, int , int);

	if (!(state = new_state()))
		return (-1);
	if (!(get_initial_state(state, argv[1])))
		return (-1);
	init_target();

	if (argc == 3 && strcmp(argv[2], "-uniform"))
		return (-1);
	if (argc == 4 && !strcmp(argv[3], "-m"))
		f = &manhattan_distance;
	else if (argc == 4 && !strcmp(argv[3], "-h"))
		f = &hamming_distance;
	else if (argc == 4 && !strcmp(argv[3], "-e"))
		f = &euclidean_distance;
	else if (argc == 4)
		return (-1);

	if (argc == 4 && !strcmp(argv[2], "-astar"))
		a_star_search(state, f);
	else if (argc == 3 && !strcmp(argv[2], "-uniform"))
		uniform_cost_search(state);
	else if (argc == 4 && !strcmp(argv[2], "-gready"))
		greedy_search(state, f);
	else 
		return (-1);
	return (1);
}
