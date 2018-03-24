/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:57:29 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/24 15:08:31 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int				is_in_explored(int **board, t_list *explored)
{
	while(explored)
	{
		if(!memcmp(*board, *((int **)(explored->content)), 
			g_size * g_size * sizeof(int)))
		{
			return(TRUE);
		}
		explored = explored->next;
	}
	return(FALSE);
}

static void			copy_paths(t_list *root, t_list **child)
{
	while(root)
	{
		list_push_back(child, root->content, sizeof(t_position));
		root = root->next;
	}
}

static void		path_push_back(t_state *root, t_state **child, t_position *path)
{
	t_position *tmp;

	// printf("%d\n", root->paths_size);
	// printf("%d %d\n", path->i, path->j);
	
	(*child)->paths_size = root->paths_size;
	(*child)->paths = realloc((*child)->paths, sizeof(t_position) * ((*child)->paths_size + 1));
	memcpy((*child)->paths, root->paths, sizeof(t_position) * ((*child)->paths_size));
	//tmp = &(*child)->paths[(*child)->paths_size];
	//tmp = path;
	(*child)->paths[(*child)->paths_size] = *path;
	// print_paths(*child);
	++(*child)->paths_size;
}

t_state			*generate_move(t_state *state, t_position pos)
{
	int			n;
	t_state		*new_state;
	t_position	*path;

	path = (t_position *)malloc(sizeof(t_position));
	new_state = init_state();
	new_state->board = init_grid();
	memcpy(*(new_state->board), *(state->board), g_size * g_size * sizeof(int));
	path->i = pos.i;
	path->j = pos.j;
	n = state->board[state->empty.i + pos.i][state->empty.j + pos.j];
	new_state->board[state->empty.i][state->empty.j] = n;
	new_state->board[state->empty.i + pos.i][state->empty.j + pos.j] = 0;
	new_state->empty = (t_position){state->empty.i + pos.i, 
		state->empty.j + pos.j};
	// list_push_back(&new_state->paths, path, sizeof(t_position));
	// print_paths(new_state);
	path_push_back(state, &new_state, path);
	// print_paths(new_state);
	return(new_state);
}

void			get_successors(t_state *state, t_state *successors[])
{
	successors[0] = NULL;
	successors[1] = NULL;
	successors[2] = NULL;
	successors[3] = NULL;

	if(state->empty.j - 1 >= 0)
		successors[0] = generate_move(state, (t_position){0, -1});
	if(state->empty.i - 1 >= 0)
		successors[1] = generate_move(state, (t_position){-1, 0});
	if(state->empty.i + 1 < g_size)
		successors[2] = generate_move(state, (t_position){1, 0});
	if(state->empty.j + 1 < g_size)
		successors[3] = generate_move(state, (t_position){0, 1});
}

void	print_paths(t_state *state)
{
	t_position	*p;
	int			i;
	
	i = -1;
	printf("PATHS\n\n");
	while(++i < state->paths_size)
		printf("{%d,%d} ", state->paths->i, state->paths->j);
	printf("\n\n");
}