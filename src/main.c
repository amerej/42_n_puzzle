/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/14 04:24:39 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int main(int argc, char *argv[])
{
	t_node		*node;

	node = NULL;

	if (!(check_arguments(argc)))
		return (-1);
	if (!(node = new_node()))
		return (-1);
	if (!(get_puzzle(node, argv[1])))
		return (-1);
	printf("n: %d\n", node->n);
	printf("puzzle:\n");
	for (int i = 0; i < node->n; i++) {
		for (int j = 0; j < node->n; j++) {
			printf("%d ", node->grid[i][j]);
		}
		printf("\n");
	}
	return (0);
}