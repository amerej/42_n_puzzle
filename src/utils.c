/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:08:18 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/23 10:09:08 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/npuzzle.h"

int			check_arguments(int argc)
{
	if (argc != 2)
	{
		printf("error : invalid number of arguments\n");
		return (ERROR);
	}
	return (SUCCESS);
}