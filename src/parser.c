/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:47:05 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 03:19:44 by aditsch          ###   ########.fr       */
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

static int		*get_values(FILE *fp, int size, int *values, int i)
{
	char 		buffer[BUFFER_SIZE];
	char		*end;
	char		*ptr;
	int			j;

	j = i * size + 1;
	fgets(buffer, BUFFER_SIZE, fp);
	ptr = buffer;
	while (ptr < buffer + BUFFER_SIZE)
	{
		values[j] = (int)strtol(ptr, &end, 10);
		if (values[j] == 0L && end == ptr)
			break;
		ptr = end;
		j++;
	}
	return (values);
}

static int		parse_puzzle(FILE *fp)
{
	int			size;
	char 		buffer[BUFFER_SIZE];
	char		*ptr;
	int			*values;
	int			i;

	size = i = 0;
	values = NULL;
	while (1)
	{
		if (feof(fp))
			break;
		if (!size)
		{
			if ((size = get_size(fp)) && !values)
				values = (int *)malloc(sizeof(int) * ((size * size) + 1));
		}
		else
		{
			get_values(fp, size, values, i);
			i++;
		}
	}
	values[0] = size;
	for (int i = 0; i < size * size + 1; i++) {
		printf("%d ", values[i]);
	}
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
	if (!parse_puzzle(fp))
		return (0);
	return (1);
}