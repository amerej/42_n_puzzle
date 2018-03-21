/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/21 02:55:21 by aditsch          ###   ########.fr       */
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

void		copy_board(int **dst_board, int **src_board)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while(++j < g_size)
			dst_board[i][j] = src_board[i][j];
	}
}