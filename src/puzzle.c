/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:42:37 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/19 00:42:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		fill_goal(t_puzzle *puzzle)
{
	t_goal g = {1, 0, 1, 0, 0, puzzle->size, puzzle->size * puzzle->size};

	while(TRUE) {
		(*puzzle->goal)[g.x + g.y * g.s] = g.cur;
		if (!g.cur)
			break;
		g.cur++;
		if(g.x + g.ix == g.s || g.x + g.ix < 0 || 
			(g.ix != 0 && (*puzzle->goal)[g.x + g.ix + g.y * g.s] != -1))
		{
			g.iy = g.ix;
			g.ix = 0;
		}
		else if(g.y + g.iy == g.s || g.y + g.iy < 0 || 
			(g.iy != 0 && (*puzzle->goal)[g.x + (g.y + g.iy) * g.s] != -1))
		{
			g.ix = -g.iy;
			g.iy = 0;
		}
		g.x += g.ix;
		g.y += g.iy;
		if (g.cur == g.ts)
			g.cur = 0;
	}
}

t_type			**init_grid(t_type size)
{
	t_type	**grid;
	t_type	i;
	t_type	j;

	if(!(grid = (t_type **)malloc(size * sizeof(t_type *))))
		return(NULL);
	if(!(grid[0] = (t_type *)malloc(size * size * sizeof(t_type))))
		return(NULL);
	i = -1;
	while(++i < size)
	{
		grid[i] = (*grid + size * i);
	}
	i = -1;
	while(++i < size)
	{
		j = -1;
		while(++j < size) {
			grid[i][j] = -1;
		}
	}
	return(grid);
}

static t_puzzle		*init_puzzle(void)
{
	t_puzzle	*puzzle;

	if(!(puzzle = (t_puzzle *)malloc(sizeof(*puzzle))))
	{
		perror("Puzzle mem alloc");
		return(NULL);
	}
	puzzle->board = NULL;
	puzzle->goal = NULL;
	puzzle->size = 0;
	return(puzzle);
}

t_puzzle		*new_puzzle()
{
	t_puzzle	*puzzle;

	if(!(puzzle = init_puzzle()))
		return(destroy_puzzle(puzzle));
	return(puzzle);
}

void			*destroy_puzzle(t_puzzle *puzzle)
{
	if((puzzle->board))
		ft_free_ptr((void **)&puzzle->board);
	if(puzzle->goal)
		ft_free_ptr((void **)&puzzle->goal);
	if(puzzle)
		ft_free_ptr((void **)&puzzle);
	return(NULL);
}