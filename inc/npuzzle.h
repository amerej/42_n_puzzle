/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/15 01:35:35 by aditsch          ###   ########.fr       */
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

# define BUFFER_SIZE 1024

# define ERROR 0
# define SUCCESS 1

typedef struct			s_stack
{
	void				*data;
	size_t				data_size;
	struct s_stack		*next;
	
}						t_stack;

typedef struct			s_goal
{
	int					cur;
	int					x;
	int					ix;
	int					y;
	int					iy;
	int					s;
	int					ts;
}						t_goal;

typedef struct			s_node
{
	int					**board;
	int					h;
	int					g;
	int					f;
	struct s_node		*parent;
	
	int					**goal;
	int					n;
}						t_node;

typedef struct			s_node_test
{
	int					x;
	int					y;
}						t_node_test;

int						check_arguments(int argc);
int						get_puzzle(t_node *node, char *filename);

void					destroy_node(t_node *node);

t_node					*new_node(void);
int						**init_board(int size);

t_stack					*stack_new_node(void const *data, size_t data_size);
int						stack_is_empty(t_stack *root);
int						stack_push(t_stack **root, void const *data, size_t data_size);
void					*stack_pop(t_stack **root);
void					*stack_peek(t_stack *root);
#endif