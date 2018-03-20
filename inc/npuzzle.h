/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/20 06:59:19 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/libft.h"
# include "utils.h"

extern int **g_target;
extern int g_size;

# define N_MAX 25
# define GRID_SIZE (N_MAX * N_MAX)
# define BUFFER_SIZE (((3 * N_MAX) + (1 * (N_MAX - 1))) + 1)

typedef struct		s_state
{
	int				**board;
	t_position		empty;
	int				path;
}					t_state;

int					check_arguments(int argc);

int					hamming_distance(int **board, int i, int j);
int					manhattan_distance(int **board, int i, int j);
int					euclidean_distance(int **board, int i, int j);
int					heuristic(int **board, int(*fn)(int **board, int i, int j));

int					**init_grid();
void				init_target();
t_state				*new_state(void);
int					get_initial_state(t_state *state, char *filename);
void				*destroy_state(t_state *state);

// DEBUG A VIRER
typedef struct		s_node_test
{
	int				x;
	int				y;
}					t_node_test;

void DEBUG_display_grid(int **grid);
void DEBUG_display_initial_state(int **board);
void DEBUG_heuristics(int **board);
void DEBUG_stack();
void DEBUG_heapp();
#endif