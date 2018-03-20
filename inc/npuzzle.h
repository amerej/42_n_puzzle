/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/20 00:38:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/libft.h"
# include "utils.h"

# define N_MAX 25
# define GRID_SIZE (N_MAX * N_MAX)
# define BUFFER_SIZE (((3 * N_MAX) + (1 * (N_MAX - 1))) + 1)

typedef short 			t_type;

typedef struct			s_puzzle
{
	t_type				**goal;
	int					path;
	t_type				size;
}						t_puzzle;

typedef struct			s_state
{
	t_type				**board;
	t_position			empty_space;
}						t_state;

int						check_arguments(int argc);

int						hamming_distance(t_puzzle *puzzle, int i, int j);
int						manhattan_distance(t_puzzle *puzzle, int i, int j);
int						euclidean_distance(t_puzzle *puzzle, int i, int j);
int						heuristic(t_puzzle *puzzle, 
							int(*fn)(t_puzzle *puzzle, int i, int j));

t_type					**init_grid(t_type size);
void					fill_goal(t_puzzle *puzzle);
t_puzzle				*new_puzzle(void);
int						get_puzzle(t_puzzle *puzzle, char *filename);
void					*destroy_puzzle(t_puzzle *puzzle);

// DEBUG A VIRER
typedef struct			s_node_test
{
	int					x;
	int					y;
}						t_node_test;

void DEBUG_display_grid(t_type **grid, t_type size);
void DEBUG_display_initial_state(t_puzzle *puzzle);
void DEBUG_heuristics(t_puzzle *puzzle);
void DEBUG_stack();
void DEBUG_heapp();
#endif