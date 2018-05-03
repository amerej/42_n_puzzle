/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:04:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/03 03:07:04 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int				init_board(t_state *state, char **split)
{
	static int	i = 0;
	int			j;

	j = -1;
	if (ft_count_split(split) != g_size || i >= g_size)
	{
		printf("Size and entry not match\n");
		return (ERROR);
	}
	while (split[++j])
	{
		if (!is_number(split[j]) ||
			atoi(split[j]) < 0 || atoi(split[j]) > (g_size * g_size) - 1)
		{
			printf("Invalid number\n");
			return (ERROR);
		}
		if (isdigit(split[j][0]) && atoi(split[j]) == 0)
			state->empty = (t_position){i, j};
		state->board[i][j] = atoi(split[j]);
	}
	++i;
	return (SUCCESS);
}

int				get_board(t_state *state, char **split)
{
	int		size;

	if (!g_size)
	{
		size = atoi(split[0]);
		if (!split[1] && size >= 3 && size <= N)
			g_size = size;
		else
		{
			ft_putstr_fd("Error: Bad size", 2);
			return (ERROR);
		}
		if (!(state->board = init_grid()))
			return (ERROR);
	}
	else if (!(init_board(state, split)))
		return (ERROR);
	return (SUCCESS);
}

int				get_initial_state(t_state *state, char *filename)
{
	FILE		*fp;

	fp = fopen(filename, "r");
	if (!fp)
	{
		perror("Opening file");
		return (ERROR);
	}
	read_puzzle(state, fp);
	if (!(g_target = init_grid()))
	{
		perror("Target mem alloc");
		return (ERROR);
	}
	return (SUCCESS);
}

int				read_lines(t_state *state, FILE *fp)
{
	char		*line;
	size_t		len;
	ssize_t		read;
	int			nb_line;

	line = NULL;
	len = 0;
	nb_line = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line[0] == '#')
			continue;
		if (!get_split(state, line))
		{
			if (line)
				free(line);
			return (ERROR);
		}
		else
		{
			nb_line++;
		}
	}
	if (line)
		free(line);
	return (nb_line - 1);
}

int				read_puzzle(t_state *state, FILE *fp)
{
	char		*line;
	size_t		len;
	ssize_t		read;
	int			nb_line;

	line = NULL;
	len = 0;
	if (!(nb_line = read_lines(state, fp)))
		return (ERROR);
	if (nb_line != g_size)
		return (ERROR);
	if (check_duplicate(state->board))
	{
		printf("Duplicate found\n");
		return (ERROR);
	}
	display_grid(state->board);
	return (SUCCESS);
}
