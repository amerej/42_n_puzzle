/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:04:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/03 03:08:12 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int		ft_count_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i]) ;
	return i;
}

int		check_duplicate(int **board)
{
	int		tab[g_size * g_size];
	int		o;
	int		y;
	int		x;

	o = -1;
	while (++o < g_size * g_size)
		tab[o] = -1;
	y = -1;
	while (++y < g_size)
	{
		x = -1;
		while (++x < g_size)
		{
			if (tab[board[y][x]] != -1)
				return (1);
			else
				tab[board[y][x]] = board[y][x];
		}
	}
	return (0);
}

int		is_number(char *str)
{
	int			i;
	size_t		len;

	i = -1;
	len = strlen(str);
	while(++i < len - 1)
	{
		if(!isdigit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}

void	free_split(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
}

int		get_split(t_state *state, char *line)
{
	char		**split;
	
	split = ft_strsplit(line, ' ');
	if (!get_board(state, split))
	{
		free_split(split);
		return (ERROR);
	}
	free_split(split);
	return (SUCCESS);
}
