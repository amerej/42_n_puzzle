/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:42:37 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 04:47:41 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

void		init_target(void)
{
	t_goal		g;

	g = (t_goal){1, 0, 1, 0, 0, g_size, g_size * g_size};
	while (TRUE)
	{
		(*g_target)[g.x + g.y * g.s] = g.cur;
		if (!g.cur)
			break ;
		g.cur++;
		if (g.x + g.ix == g.s || g.x + g.ix < 0 ||
			(g.ix != 0 && (*g_target)[g.x + g.ix + g.y * g.s] != -1))
		{
			g.iy = g.ix;
			g.ix = 0;
		}
		else if (g.y + g.iy == g.s || g.y + g.iy < 0 ||
			(g.iy != 0 && (*g_target)[g.x + (g.y + g.iy) * g.s] != -1))
		{
			g.ix = -g.iy;
			g.iy = 0;
		}
		g.x += g.ix;
		g.y += g.iy;
		g.cur = (g.cur == g.ts) ? 0 : g.cur;
	}
}

int			**init_grid(void)
{
	int		**grid;
	int		i;
	int		j;

	if (!(grid = (int **)malloc(g_size * sizeof(int *))))
		return (NULL);
	if (!(grid[0] = (int *)malloc(g_size * g_size * sizeof(int))))
		return (NULL);
	i = -1;
	while (++i < g_size)
		grid[i] = (*grid + g_size * i);
	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
			grid[i][j] = -1;
	}
	return (grid);
}

t_state		*init_state(void)
{
	t_state		*state;

	if (!(state = (t_state *)malloc(sizeof(*state))))
	{
		perror("State mem alloc");
		return (NULL);
	}
	state->board = NULL;
	state->empty = (t_position){0, 0};
	state->paths = NULL;
	state->paths_size = 0;
	return (state);
}

t_state		*new_state(void)
{
	t_state		*state;

	if (!(state = init_state()))
	{
		destroy_state(state);
		return (NULL);
	}
	g_target = NULL;
	g_size = 0;
	return (state);
}

void		*destroy_state(t_state *state)
{
	if (state->board[0])
		ft_free_ptr((void **)&state->board[0]);
	if (state->board)
		ft_free_ptr((void **)&state->board);
	if (state->paths)
		ft_free_ptr((void **)&state->paths);
	if (g_target[0])
		ft_free_ptr((void **)&g_target[0]);
	if (g_target)
		ft_free_ptr((void **)&g_target);
	if (g_initial[0])
		ft_free_ptr((void **)&g_initial[0]);
	if (g_initial)
		ft_free_ptr((void **)&g_initial);
	if (state)
		ft_free_ptr((void **)&state);
	return (NULL);
}
