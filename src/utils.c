/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 01:17:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

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
