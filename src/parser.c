/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:04:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 19:22:58 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void			fill_board(t_puzzle *puzzle, char buffer[], int i)
{
	char		*end;
	char		*ptr;
	int			j;
	int			tmp;

	j = 0;
	ptr = buffer;
	while(ptr < buffer + BUFFER_SIZE)
	{
		tmp = (t_type)strtol(ptr, &end, 10);
		if (tmp == 0 && end == ptr)
			break;
		
		puzzle->board[i][j] = tmp;
		ptr = end;
		j++;
	}
}

static int			parse_puzzle(t_puzzle *puzzle, char buffer[])
{
	char				*ptr;
	static t_type		i = 0;
	
	if (!puzzle->size)
	{
		if ((puzzle->size = strtol(buffer, &ptr, 10)) && !(puzzle->board))
		{
			if(puzzle->size < 3 || puzzle->size > 25)
			{
				ft_putstr_fd("Error: Bad size", 2);
				return(ERROR);
			}
			if(!(puzzle->board = init_grid(puzzle->size)))
			{
				perror("Board mem alloc");
				return(ERROR);
			}
		}
	}
	else
	{
		fill_board(puzzle, buffer, i++);
	}
	return (SUCCESS);
}

int					get_puzzle(t_puzzle *puzzle, char *filename)
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
		if (!(parse_puzzle(puzzle, buffer)))
			return (ERROR);
	}
	if(!(puzzle->goal = init_grid(puzzle->size)))
	{
		perror("Goal mem alloc");
		return(ERROR);
	}
	fill_goal(puzzle);
	return(SUCCESS);
}