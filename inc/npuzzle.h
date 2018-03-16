/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 17:35:37 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include "../libft/libft.h"
# include <math.h>

# define ERROR 0
# define SUCCESS 1

# define N_MAX 25
# define GRID_SIZE (N_MAX * N_MAX)
# define BUFFER_SIZE (((3 * N_MAX) + (1 * (N_MAX - 1))) + 1)

typedef short 			t_type;

typedef struct			s_stack
{
	void				*data;
	size_t				data_size;
	struct s_stack		*next;
	
}						t_stack;

typedef struct			s_heap
{
	void				*data;
	size_t				data_size;
	struct s_heap		*next;
	
}						t_heap;

typedef struct			s_heapp
{
	void				*data;
	size_t				data_size;
	struct s_heapp		*next;
	
}						t_heapp;

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

typedef struct			s_position
{
	int					i;
	int					j;
}						t_position;

typedef struct			s_node_test
{
	int					x;
	int					y;
}						t_node_test;

typedef struct			s_puzzle
{
	short				**board;
	short				**goal;
	short				empty_space;
	short				size;
}						t_puzzle;

int						check_arguments(int argc);

t_stack					*stack_new_node(void const *data, size_t data_size);
int						stack_is_empty(t_stack *root);
int						stack_push(t_stack **root, void const *data, size_t data_size);
void					*stack_pop(t_stack **root);
void					*stack_peek(t_stack *root);

int						hamming_distance(t_puzzle *puzzle);
int						manhattan_distance(t_puzzle *puzzle);
int						euclidean_distance(t_puzzle *puzzle);

t_type					**init_grid(t_type size);
void					fill_goal(t_puzzle *puzzle);
t_puzzle				*new_puzzle(void);
int						get_puzzle(t_puzzle *puzzle, char *filename);
void					*destroy_puzzle(t_puzzle *puzzle);

// DEBUG A VIRER
void	DEBUG_display_grid(t_type **grid, t_type size);
void	DEBUG_display_initial_state(t_puzzle *puzzle);
void	DEBUG_heuristics(t_puzzle *puzzle);
void	DEBUG_stack();
#endif