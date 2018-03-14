/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/13 23:59:45 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "npuzzle.h"

int		check_arguments(int argc)
{
	if (argc != 2)
	{
		printf("error : invalid number of arguments\n");
		return (0);
	}
	return (1);
}