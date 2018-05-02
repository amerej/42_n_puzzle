/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:04:17 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/03 00:21:45 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int				ft_count_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i]) ;
	return i;
}

static int		check_duplicate(int **board)
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

static int		is_number(char *str)
{
	int			i;
	size_t		len;

	i = -1;
	len = strlen(str);
	while(++i < len - 1)
	{
		if(!isdigit(str[i]))
		{
			printf("%c", str[i]);
			return (0);
		}
	}
	return (1);
}

void			free_split(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		printf("free %s\n", split[i]);
		free(split[i]);
	}
	free(split);
}

static int		init_board(t_state *state, char **split)
{
	static int	i = 0;
	int			j;

	j = -1;
	if (ft_count_split(split) != g_size)
	{
		printf("Size and entry not match\n");
		return (ERROR);		
	}
	while (split[++j])
	{
		if (!is_number(split[j]) ||
			atoi(split[j]) < 0 || atoi(split[j]) > (g_size * g_size) - 1)
		{
			printf("|%s|", split[j]);
			printf("Invalid number\n");
			return (ERROR);
		}
		if (isdigit(split[j][0]) && atoi(split[j]) == 0)
			state->empty = (t_position){i, j};
		state->board[i][j] = atoi(split[j]);
	}
	i++;
	return (i);
}

static int		get_board(t_state *state, char **split)
{
	int				j = -1;
	int				size;

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
		{
			return (ERROR);
		}
	}
	else if (!init_board(state, split))
		return (ERROR);
	return (SUCCESS);
}

int				get_split(t_state *state, char *line)
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

int			read_puzzle(t_state *state, FILE *fp)
{
	char		*line;
	size_t		len;
	ssize_t		read;

	line = NULL;
	len = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line[0] == '#')
			continue;
		if (!get_split(state, line))
		{
			free(line);
			return (ERROR);
		}
	}
	if (line)
		free(line);
	if (check_duplicate(state->board))
	{
		printf("Duplicate found\n");
		return (ERROR);
	}
	display_grid(state->board);
	return (SUCCESS);
}
