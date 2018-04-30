/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/04/30 23:05:16 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/npuzzle.h"

int		check_arguments(int argc)
{
	if (argc != 2)
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
	if (!(*open))
		return ;
	free_open(&((*open))->next);
	free_state((*open)->data);
	free((*open));
}

void	free_state(t_state *node)
{
	free(node->paths);
	free(node->board[0]);
	free(node->board);
	free(node);
}
