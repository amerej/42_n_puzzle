/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:47:05 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 04:22:34 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int		get_size(FILE *fp)
{
	char 		buffer[BUFFER_SIZE];
	char		*ptr;
	int			size;

	fgets(buffer, BUFFER_SIZE, fp);
	size = strtol(buffer, &ptr, 10);
	return size;
}

static void		fill_grid(FILE *fp, int size, int **grid, int i)
{
	char 		buffer[BUFFER_SIZE];
	char		*end;
	char		*ptr;
	int			j;
	int			tmp;

	j = 0;
	fgets(buffer, BUFFER_SIZE, fp);
	ptr = buffer;
	while (ptr < buffer + BUFFER_SIZE)
	{
		tmp = (int)strtol(ptr, &end, 10);
		if (tmp == 0 && end == ptr)
			break;
		grid[i][j] = tmp;
		ptr = end;
		j++;
	}
}

static int		parse_puzzle(FILE *fp, t_node *node)
{
	int			size, i;
	char 		buffer[BUFFER_SIZE], *ptr;

	size = i = 0;
	while (1) {
		if (feof(fp))
			break;
		if (!size) {
			if ((size = get_size(fp)) && !node->grid) {
				if (!(node->grid = init_grid(size))) {
					printf("error: init_grid in parser");
					return (0);
				}
			}
		}
		else {
			fill_grid(fp, size, node->grid, i);
			i++;
		}
	}
	node->n = size;
	return (1);
}

int				get_puzzle(t_node *node, char *filename)
{
	FILE	*fp;

	errno = 0;
	fp = fopen(filename, "r");

	if(fp == NULL || errno != 0)
	{
		perror("fopen");
		return (0);
	}
	if (!parse_puzzle(fp, node))
		return (0);
	return (1);
}