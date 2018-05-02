/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/02 17:09:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/libft.h"
# include "utils.h"

# define N 8
# define N_MAX ((N * N) - 1)
# define BUFFER_SIZE (((3 * N) + (1 * (N - 1))) + 1)

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_btree	*next;
	int				value;
	int				took;
}					t_btree;

typedef struct		s_state
{
	int				**board;
	int				paths_size;
	t_position		empty;
	t_position		*paths;
}					t_state;

extern int			**g_target;
extern int			g_size;

int					tb_explore(t_btree **explored, int **board, int x, int y);
void				tb_add(t_btree **explored, int **board, int x, int y);

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
void				get_successors(t_state *state, t_state *successors[4]);
int					is_in_explored(int **board, t_list *explored);

void				a_star_search(t_state *state, int(*fn)(int **board, int i,
						int j));
void				greedy_search(t_state *state, int(*fn)(int **board, int i,
						int j));
void				uniform_cost_search(t_state *state);

void				free_explored(t_btree **explored);
void				free_open(t_heapp **open);
void				free_state(t_state *node);

void				display_grid(int **grid);
void				display_initial_state(int **board);
void				display_heuristics(int **board);
void				display_paths(t_state *state);

int					read_puzzle(t_state *state, FILE *fp);
#endif
