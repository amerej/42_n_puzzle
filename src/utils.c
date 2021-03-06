/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 06:12:19 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

void		free_explored(t_btree **explored)
{
	if ((*explored)->next)
		free_explored(&(*explored)->next);
	if ((*explored)->left)
		free_explored(&(*explored)->left);
	if ((*explored)->right)
		free_explored(&(*explored)->right);
	free((*explored));
	(*explored) = NULL;
}

void		free_open(t_heapp **open)
{
	t_heapp		*tmp;

	tmp = NULL;
	while ((*open))
	{
		tmp = (*open);
		(*open) = (*open)->next;
		free_state((tmp)->data);
		free(tmp);
	}
}

void		free_state(t_state *node)
{
	free(node->paths);
	free(node->board[0]);
	free(node->board);
	free(node);
}

int			count_successors(t_state *successors[4])
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (++i < 4)
		if (successors[i])
			count++;
	return (count);
}

t_position	get_empty(int **board)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			if (board[i][j] == 0)
				return ((t_position) {i, j});
		}
	}
	return ((t_position) {0, 0});
}
