/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:16:33 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 21:30:55 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

static t_position	get_position(int n_board)
{
	int			i;
	int			j;
	t_position	pos;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			if (n_board == g_target[i][j])
			{
				pos.i = i;
				pos.j = j;
				return (pos);
			}
		}
	}
	return ((t_position){-1, -1});
}

int					hamming_distance(int **board, int i, int j)
{
	int		res;
	int		n_board;
	int		n_target;

	res = 0;
	n_board = board[i][j];
	n_target = g_target[i][j];
	if (n_board && n_board != n_target)
		res++;
	return (res);
}

int					manhattan_distance(int **board, int i, int j)
{
	int				res;
	int				n_board;
	int				n_target;
	t_position		pos;

	res = 0;
	n_board = board[i][j];
	n_target = g_target[i][j];
	if (n_board && n_board != n_target)
	{
		pos = get_position(n_board);
		res += (abs(i - pos.i) + abs(j - pos.j));
	}
	return (res);
}

int					euclidean_distance(int **board, int i, int j)
{
	int				res;
	int				n_board;
	int				n_target;
	t_position		pos;
	t_position		dist;

	res = 0;
	n_board = board[i][j];
	n_target = g_target[i][j];
	if (n_board != n_target)
	{
		pos = get_position(n_board);
		dist.i = i - pos.i;
		dist.j = j - pos.j;
		res += floor(sqrt(dist.i * dist.i + dist.j * dist.j));
	}
	return (res);
}

int					heuristic(int **board,
						int (*fn) (int **board, int i, int j))
{
	int		i;
	int		j;
	int		res;

	i = -1;
	res = 0;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
			res += fn(board, i, j);
	}
	return (res);
}
