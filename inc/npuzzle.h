/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/24 15:57:28 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/libft.h"
# include "utils.h"

# define N_MAX 25
# define BUFFER_SIZE (((3 * N_MAX) + (1 * (N_MAX - 1))) + 1)

typedef struct		s_state
{
	int				**board;
	int				paths_size;
	t_position		empty;
	t_position		*paths;
}					t_state;

extern int 			**g_target;
extern int 			g_size;

int					check_arguments(int argc);

int					hamming_distance(int **board, int i, int j);
int					manhattan_distance(int **board, int i, int j);
int					euclidean_distance(int **board, int i, int j);
int					heuristic(int **board, int(*fn)(int **board, int i, int j));

int					**init_grid();
void				init_target();
t_state				*init_state(void);
t_state				*new_state(void);
int					get_initial_state(t_state *state, char *filename);
void				*destroy_state(t_state *state);

void				print_paths(t_state *state);
t_state				*generate_move(t_state *state, t_position pos);
void				get_successors(t_state *state, t_state *successors[]);
int					is_in_explored(int **board, t_list *explored);

void				a_star_search(t_state *state, int(*fn)(int **board, int i, 
						int j));
void				greedy_search(t_state *state, int(*fn)(int **board, int i, 
						int j));
void				uniform_cost_search(t_state *state, int(*fn)(int **board, int i, 
						int j));

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
void printList(t_list *n);
#endif