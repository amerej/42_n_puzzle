/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/16 02:27:03 by aditsch          ###   ########.fr       */
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
	
	//TEST AFFICHAGE
	DEBUG_display_initial_state(node);
	DEBUG_heuristics(node);

	// TEST STACK
	// DEBUG_stack();
	
	return (0);
}
