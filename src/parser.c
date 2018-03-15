/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:47:05 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 22:04:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int			fill_goal(t_node *node)
{
	t_goal g = {1, 0, 1, 0, 0, node->n, node->n * node->n};

	if (!(node->goal = init_board(g.s)))
		return (ERROR);
	while(TRUE) {
		(*node->goal)[g.x + g.y * g.s] = g.cur;
		if (!g.cur)
			break;
		g.cur++;
		if (g.x + g.ix == g.s || g.x + g.ix < 0 || 
			(g.ix != 0 && (*node->goal)[g.x + g.ix + g.y * g.s] != -1)) {
			g.iy = g.ix;
			g.ix = 0;
		}
		else if (g.y + g.iy == g.s || g.y + g.iy < 0 || 
			(g.iy != 0 && (*node->goal)[g.x + (g.y + g.iy) * g.s] != -1)) {
			g.ix = -g.iy;
			g.iy = 0;
		}
		g.x += g.ix;
		g.y += g.iy;
		if (g.cur == g.ts)
			g.cur = 0;
	}
	return (SUCCESS);
}

static void			fill_board(t_node *node, char buffer[], int i)
{
	char		*end;
	char		*ptr;
	int			j;
	int			tmp;

	j = 0;
	ptr = buffer;
	while (ptr < buffer + BUFFER_SIZE)
	{
		tmp = (int)strtol(ptr, &end, 10);
		if (tmp == 0 && end == ptr)
			break;
		node->board[i][j] = tmp;
		ptr = end;
		j++;
	}
}

static int			parse_puzzle(t_node *node, char buffer[], int *i)
{
	char	*ptr;
	
	if (!node->n)
	{
		if ((node->n = strtol(buffer, &ptr, 10)) && !node->board)
			if (!(node->board = init_board(node->n)))
				return(ERROR);
	}
	else
		fill_board(node, buffer, (*i)++);
	return (SUCCESS);
}

int					get_puzzle(t_node *node, char *filename)
{
	FILE	*fp;
	char	buffer[BUFFER_SIZE];
	int		i;

	fp = fopen(filename, "r");
	i = 0;
	if(!fp)
	{
		perror("Error opening file");
		return (ERROR);
	}
	while (TRUE) {
		if (!fgets(buffer, BUFFER_SIZE, fp))
			break;
		if (!(parse_puzzle(node, buffer, &i)))
			return (ERROR);
	}
	if (!(fill_goal(node)))
		return (ERROR);
	return (SUCCESS);
}