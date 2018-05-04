/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 05:46:56 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int		**g_initial;
int		**g_target;
int		g_size;

int		main(int argc, char *argv[])
{
	t_state		*state;
	t_argv		user_argv;

	state = NULL;
	user_argv = parse_argv(argc, argv);
	if (user_argv.err_code)
	{
		argv_err(user_argv.err_code);
		return (EXIT_FAILURE);
	}
	if (!(state = new_state()))
		return (EXIT_FAILURE);
	if (!(get_initial_state(state, argv[1])))
	{
		destroy_state(state);
		return (EXIT_FAILURE);
	}
	init_target();
	user_argv.search(state, user_argv.heuristic);
	return (0);
}
