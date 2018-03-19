/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:16:33 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/19 23:53:48 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static t_position	get_position(t_type **goal, int size, t_type n_board)
{
	int			i;
	int			j;
	t_position	pos;

	i = -1;
	while(++i < size)
	{
		j = -1;
		while(++j < size)
		{
			if(n_board == goal[i][j])
			{
				pos.i = i;
				pos.j = j;
				return(pos);
			}
		}
	}
	return(pos);
}

int					hamming_distance(t_puzzle *puzzle, int i, int j)
{
	int			res;
	t_type		n_board;
	t_type		n_goal;

	res = 0;
	n_board = puzzle->board[i][j];
	n_goal = puzzle->goal[i][j];
	if (n_board && n_board != n_goal)
		res++;
	return(res);
}

int					manhattan_distance(t_puzzle *puzzle, int i, int j)
{
	int				res;
	t_type			n_board;
	t_type			n_goal;
	t_position		pos;

	res = 0;
	n_board = puzzle->board[i][j];
	n_goal = puzzle->goal[i][j];
	if(n_board && n_board != n_goal)
	{
		pos = get_position(puzzle->goal, puzzle->size, n_board);
		res += (abs(i - pos.i) + abs(j - pos.j));
	}
	return(res);
}

int					euclidean_distance(t_puzzle *puzzle, int i, int j)
{
	int				res;
	t_type			n_board;
	t_type			n_goal;
	t_position		pos;
	t_position		dist;

	res = 0;
	n_board = puzzle->board[i][j];
	n_goal = puzzle->goal[i][j];
	if (puzzle->board[i][j] != puzzle->goal[i][j])
	{
		pos = get_position(puzzle->goal, puzzle->size, n_board);
		dist.i = i - pos.i;
		dist.j = j - pos.j;
		res += floor(sqrt(dist.i * dist.i + dist.j * dist.j));
	}
	return(res);
}

int					heuristic(t_puzzle *puzzle, int(*fn)(t_puzzle *puzzle, int i, int j))
{
	int		i;
	int		j;
	int		res;

	i = -1;
	res = 0;
	while(++i < puzzle->size)
	{
		j = -1;
		while(++j < puzzle->size)
		{
			res += fn(puzzle, i, j);
		}
	}
	return(res);
}