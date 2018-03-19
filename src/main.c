/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:12:45 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/19 02:32:13 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int main(int argc, char *argv[])
{
	t_puzzle	*puzzle;

	puzzle = NULL;
	if (!(check_arguments(argc)))
		return (-1);
	if (!(puzzle = new_puzzle()))
		return (-1);
	if (!(get_puzzle(puzzle, argv[1])))
		return (-1);
	
	//TEST AFFICHAGE
	DEBUG_display_initial_state(puzzle);
	DEBUG_heuristics(puzzle);
  DEBUG_heapp();

	// TEST STACK
	// DEBUG_stack();
	return (0);
}