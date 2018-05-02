/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/02 23:04:15 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int		check_arguments(int argc)
{
	if (argc < 3 || argc > 4)
	{
		printf("error : invalid number of arguments\n");
		return (ERROR);
	}
	return (SUCCESS);
}

void	free_explored(t_btree **explored)
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

void	free_open(t_heapp **open)
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

void	free_state(t_state *node)
{
	free(node->paths);
	free(node->board[0]);
	free(node->board);
	free(node);
}
