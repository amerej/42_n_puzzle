/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 23:28:19 by nrouzeva          #+#    #+#             */
/*   Updated: 2018/05/04 03:13:14 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

t_heuristic		get_heuristic(int argc, char *argv[])
{
	if (argc == 4 && !strcmp(argv[3], "-m"))
		return (manhattan_distance);
	else if (argc == 4 && !strcmp(argv[3], "-h"))
		return (hamming_distance);
	else if (argc == 4 && !strcmp(argv[3], "-e"))
		return (euclidean_distance);
	return (NULL);
}

t_search		get_search(int argc, char *argv[])
{
	if (argc == 4 && !strcmp(argv[2], "-astar"))
		return (a_star_search);
	else if (argc == 3 && !strcmp(argv[2], "-uniform"))
		return (uniform_cost_search);
	else if (argc == 4 && !strcmp(argv[2], "-greedy"))
		return (greedy_search);
	return (NULL);
}

t_argv			parse_argv(int argc, char **argv)
{
	t_argv		res;

	res.heuristic = NULL;
	res.search = NULL;
	res.err_code = 0;
	if (argc < 3 || argc > 4)
		res.err_code = 1;
	else if (argc == 3 && strcmp(argv[2], "-uniform"))
		res.err_code = 1;
	else if (!(res.heuristic = get_heuristic(argc, argv)) &&
		!(argc == 3 && !strcmp(argv[2], "-uniform")))
		res.err_code = 1;
	else if (!(res.search = get_search(argc, argv)))
		res.err_code = 1;
	return (res);
}

void			argv_err(int err_code)
{
	if (err_code == 1)
		printf("err_code [1]: Invalid arguments\n");
	printf("Usage : npuzzle [file ...] \
[-greedy [-m -e -h] -astar [-m -e -h] -uniform]\n");
}
