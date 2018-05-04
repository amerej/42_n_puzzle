/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:10:58 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/04 03:40:11 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/libft.h"
# include "utils.h"
# include <sys/types.h>
# include <sys/stat.h>

# define N 8
# define N_MAX ((N * N) - 1)
# define BUFFER_SIZE (((3 * N) + (1 * (N - 1))) + 1)

extern int			**g_target;
extern int			g_size;

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

typedef struct		s_search_var
{
	t_btree			*explored;
	t_heapp			*open;
	t_state			*node;
	t_state			*successors[4];
	int				t_cmplx;
	int				s_cmplx;
}					t_search_var;

typedef int			(*t_heuristic)(int **board, int i, int j);
typedef void		(*t_search)(t_state *state, t_heuristic);

typedef struct		s_argv
{
	t_heuristic		heuristic;
	t_search		search;
	int				err_code;
}					t_argv;

int					tb_explore(t_btree **explored, int **board, int x, int y);
void				tb_add(t_btree **explored, int **board, int x, int y);

int					hamming_distance(int **board, int i, int j);
int					manhattan_distance(int **board, int i, int j);
int					euclidean_distance(int **board, int i, int j);
int					heuristic(int **board, int(*fn)(int **board, int i, int j));

int					**init_grid();
void				init_target();
t_state				*init_state(void);
t_state				*new_state(void);
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
void				display_initial_state(int **board, char *algo);
void				display_heuristics(int **board);
void				display_paths(t_state *state);
void				display_solution(t_search_var s);

int					init_board(t_state *state, char **split);
int					get_board(t_state *state, char **split);
int					get_initial_state(t_state *state, char *filename);
int					read_lines(t_state *state, FILE *fp);
int					read_puzzle(t_state *state, FILE *fp);

int					ft_count_split(char **split);
int					check_duplicate(int **board);
int					is_number(char *str);
void				free_split(char **split);
int					get_split(t_state *state, char *line);

t_heuristic			get_heuristic(int argc, char *argv[]);
t_search			get_search(int argc, char *argv[]);
t_argv				parse_argv(int argc, char **argv);
void				argv_err(int err_code);

int					count_successors(t_state *successors[4]);
#endif
