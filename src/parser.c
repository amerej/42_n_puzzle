/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:04:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/20 07:56:01 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void			init_board(t_state *state, char buffer[], int i)
{
	char		*end;
	char		*ptr;
	int			j;
	int			tmp;

	j = 0;
	ptr = buffer;
	while(ptr < buffer + BUFFER_SIZE)
	{
		tmp = (int)strtol(ptr, &end, 10);
		if (tmp == 0 && end == ptr)
			break;
		if(tmp == 0)
			state->empty = (t_position){i, j};
		state->board[i][j] = tmp;
		ptr = end;
		j++;
	}
}

static int			get_board(t_state *state, char buffer[])
{
	char			*ptr;
	static int		i = 0;
	
	if (!g_size)
	{
		if ((g_size = strtol(buffer, &ptr, 10)) && !state->board)
		{
			if(g_size < 3 || g_size > 25)
			{
				ft_putstr_fd("Error: Bad size", 2);
				return(ERROR);
			}
			if(!(state->board = init_grid()))
			{
				perror("Board mem alloc");
				return(ERROR);
			}
		}
	}
	else
		init_board(state, buffer, i++);
	return (SUCCESS);
}

int					get_initial_state(t_state *state, char *filename)
{
	FILE	*fp;
	char	buffer[BUFFER_SIZE];

	fp = fopen(filename, "r");
	if(!fp)
	{
		perror("Opening file");
		return (ERROR);
	}
	while(TRUE)
	{
		if (!fgets(buffer, BUFFER_SIZE, fp))
			break;
		if (!(get_board(state, buffer)))
			return (ERROR);
	}
	if(!(g_target = init_grid()))
	{
		perror("Target mem alloc");
		return(ERROR);
	}
	return(SUCCESS);
}