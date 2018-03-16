/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:16:33 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 17:47:03 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static t_position		get_position(t_type **goal, int size, t_type n)
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
			if(n == goal[i][j])
			{
				pos.i = i;
				pos.j = j;
				return(pos);
			}
		}
	}
	return(pos);
}

int				hamming_distance(t_puzzle *puzzle)
{
	int			i;
	int			j;
	int			res;

	i = -1;
	res = 0;
	while(++i < puzzle->size)
	{
		j = -1;
		while(++j < puzzle->size)
		{
			if (puzzle->board[i][j] != 0 && 
				puzzle->board[i][j] != puzzle->goal[i][j])
			{
				res++;
			}
		}
	}
	return(res);
}

int		manhattan_distance(t_puzzle *puzzle)
{
	int				i;
	int				j;
	int				res;
	t_position		pos;

	i = -1;
	res = 0;
	while(++i < puzzle->size)
	{
		j = -1;
		while(++j < puzzle->size)
		{
			if (puzzle->board[i][j] != 0 && 
				puzzle->board[i][j] != puzzle->goal[i][j])
			{
				pos = get_position(puzzle->goal, puzzle->size, 
					puzzle->board[i][j]);
				res += (abs(i - pos.i) + abs(j - pos.j));
			}
		}
	}
	return(res);
}

int		euclidean_distance(t_puzzle *puzzle)
{
	int				i;
	int				j;
	int				res;
	t_position		pos;
	t_position		dist;

	i = -1;
	res = 0;
	while(++i < puzzle->size)
	{
		j = -1;
		while(++j < puzzle->size)
		{
			if (puzzle->board[i][j] != puzzle->goal[i][j])
			{
				pos = get_position(puzzle->goal, puzzle->size, 
					puzzle->board[i][j]);
				dist.i = i - pos.i;
				dist.j = j - pos.j;
				res += floor(sqrt(dist.i * dist.i + dist.j * dist.j));
			}
		}
	}
	return(res);
}