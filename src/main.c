/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/22 16:06:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/npuzzle.h"

int			**g_target;
int			g_size;

void        a_star_search(t_state *state, int(*fn)(int **board, int i, int j));

int main(int argc, char *argv[])
{
	t_state		*state;

	state = NULL;
	if (!(check_arguments(argc)))
		return (-1);
	if (!(state = new_state()))
		return (-1);
	if (!(get_initial_state(state, argv[1])))
		return (-1);
	init_target();

	//TEST DEBUG
	DEBUG_display_initial_state(state->board);
	DEBUG_heuristics(state->board);
    a_star_search(state, manhattan_distance);

	//TEST SUCCESSORS
	// t_state *successors[4];

	// get_successors(state, successors);
	// if (successors[0])
	// {
	// 	printf("Successor 1\n");
	// 	DEBUG_display_grid(successors[0]->board);
	// }
	// if (successors[1])
	// {
	// 	printf("Successor 2\n");
	// 	DEBUG_display_grid(successors[1]->board);
	// }
	// if (successors[2])
	// {
	// 	printf("Successor 3\n");
	// 	DEBUG_display_grid(successors[2]->board);
	// }
	// if (successors[3])
	// {
	// 	printf("Successor 4\n");
	// 	DEBUG_display_grid(successors[3]->board);
	// }

	// TEST STACK
	// DEBUG_stack();

	// TEST HEAPP
	// DEBUG_heapp();

	return (0);
}
int         a_star_cost(t_state *node, int distance)
{
    return(ft_list_size(node->paths) + distance);
}

void        printList(t_list *n)
{
    while (n != NULL)
    {
        DEBUG_display_grid(n->content);
		printf("\n");
        n = n->next;
    }
}

int         board_cmp(int **a, int **b)
{
    int     i;
    int     j;

    i = -1;
    while(++i < g_size)
    {
        j = -1;
		while(++j < g_size)
		{
			if(a[i][j] != b[i][j])
			{
				return(FALSE);
			}
		}
	}
    return(TRUE);
}

int         is_in_explored(int **board, t_list *explored)
{
	// printf("explored len = %d\n", ft_list_size(explored));
	// printList(explored);
	while(explored)
	{
	if(board_cmp(board, explored->content))
		{
			return(TRUE);
		}
		explored = explored->next;
	}
	return(FALSE);
}

void        a_star_search(t_state *state, int(*fn)(int **board, int i, int j))
{
    t_list      *explored;
    t_heapp     *open;
    t_state     *node;
    t_state     *successors[4];
    int         i;

    explored = NULL;
    open = NULL;
    list_push_back(&explored, state->board, (g_size * g_size) * sizeof(int));
    heapp_push(&open, state, a_star_cost(state, heuristic(state->board, fn)), sizeof(t_state));
    while(!heapp_is_empty(open))
    {
        node = heapp_pop(&open);
        if(board_cmp(node->board, g_target))
        {
            return ; // To implement
        }
        get_successors(node, successors);
        i = -1;
        while(++i < 4)
        {
            if(successors[i] && !is_in_explored(successors[i]->board, explored))
            {
				// DEBUG_display_grid(successors[i]->board);
            	list_push_back(&explored, successors[i]->board, (g_size * g_size) * sizeof(int));
				DEBUG_display_grid(successors[i]->board);
				printf("\n");
				heapp_push(&open, successors[i], a_star_cost(successors[i], heuristic(successors[i]->board, fn)), sizeof(t_state));
            }
        }
    }
    return ; // To implement
}

t_state		*generate_move(t_state *state, t_position pos)
{
	int			n;
	t_state		*new_state;

	new_state = init_state();
	new_state->board = init_grid();
	copy_board(new_state->board, state->board);
	while(state->paths)
	{
		list_push_back(&new_state->paths, state->paths->content, sizeof(t_position));
		state->paths = state->paths->next;
	}
	n = state->board[state->empty.i + pos.i][state->empty.j + pos.j];
	new_state->board[state->empty.i][state->empty.j] = n;
	new_state->board[state->empty.i + pos.i][state->empty.j + pos.j] = 0;
	new_state->empty = (t_position){state->empty.i + pos.i, state->empty.j + pos.j};
	list_push_back(&new_state->paths, &pos, sizeof(t_position));
	return(new_state);
}

void		get_successors(t_state *state, t_state *successors[])
{
	t_position		pos;
	
	if(state->empty.j - 1 >= 0)
		successors[0] = generate_move(state, (t_position){0, -1}); // successors[0] = generate_move(state, 0, -1);
	else
		successors[0] = NULL;
	if(state->empty.i - 1 >= 0)
		successors[1] = generate_move(state, (t_position){-1, 0}); // successors[1] = generate_move(state, -1, 0);
	else
		successors[1] = NULL;
	if(state->empty.i + 1 < g_size)
		successors[2] = generate_move(state, (t_position){1, 0}); // successors[2] = generate_move(state, 1, 0);
	else
		successors[2] = NULL;
	if(state->empty.j + 1 < g_size)
		successors[3] = generate_move(state, (t_position){0, 1}); // successors[3] = generate_move(state, 0, 1);
	else
		successors[3] = NULL;
}