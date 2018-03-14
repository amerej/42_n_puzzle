/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 06:33:15 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "../libft/libft.h"
# include <math.h>

# define BUFFER_SIZE 255

typedef struct			s_node
{
	int					**grid;
	int					**goal;
	int					h;
	int					n;
	struct s_node		*parent;
	
}						t_node;

int						check_arguments(int argc);
int						get_puzzle(t_node *node, char *filename);

void					destroy_node(t_node *node);

t_node					*new_node(void);
int						**init_grid(int size);

int 					make_goal(t_node *node, int size);
#endif