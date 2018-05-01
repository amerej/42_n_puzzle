/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/02 01:01:18 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int		**g_target;
int		g_size;

void	show_usage(void)
{
	printf("usage : npuzzle [file ...] [-gready -astar -uniform] [-m -e -h]\n");
}

int		main(int argc, char *argv[])
{
	t_state		*state;

	state = NULL;
	if (!(check_arguments(argc)))
		return (-1);
	if (!command_line_parser(argc, argv))
	{
		show_usage();
		return (-1);
	}
	return (0);
}
