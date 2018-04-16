#include "../inc/npuzzle.h"

void	tb_add(t_btree **list, int **board, int x, int y)
{
	if (!(*list))
	{
		(*list) = (t_btree *)ft_memalloc(sizeof(t_btree));
		(*list)->right = NULL;
		(*list)->left = NULL;
		(*list)->next = NULL;
		(*list)->value = board[y][x];
		(*list)->took = FALSE;
		if (x + 1 != g_size)
			x += 1;
		else
		{
			x = 0;
			if (y + 1 != g_size)
				y += 1;
			else
			{
				(*list)->took = TRUE;
				return ;
			}
		}
		if (board[y][x] > (*list)->value)
			tb_add(&(*list)->right, board, x, y);
		else
			tb_add(&(*list)->left, board, x, y);
	}
	else if ((*list)->value == board[y][x])
	{
		if (x + 1 != g_size)
			x += 1;
		else
		{
			x = 0;
			if (y + 1 != g_size)
				y += 1;
			else
			{
				(*list)->took = TRUE;
				return ;
			}
		}
		if (board[y][x] > (*list)->value)
			tb_add(&(*list)->right, board, x, y);
		else
			tb_add(&(*list)->left, board, x, y);
	}
	else if ((*list)->value != board[y][x])
		tb_add(&(*list)->next, board, x, y);
}

int				tb_explore(t_btree **explored, int **board, int x, int y)
{
	if (!(*explored))
		return FALSE;
	else if ((*explored)->value == board[y][x])
	{
		if (x + 1 != g_size)
			x += 1;
		else
		{
			x = 0;
			if (y + 1 != g_size)
				y += 1;
			else
				return (*explored)->took;
		}
		if (board[y][x] > (*explored)->value)
			return tb_explore(&(*explored)->right, board, x, y);
		else
			return tb_explore(&(*explored)->left, board, x, y);
	}
	else if ((*explored)->value != board[y][x])
		return tb_explore(&(*explored)->next, board, x, y);
}
