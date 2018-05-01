/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 00:20:44 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:16:14 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct	s_goal
{
	int			cur;
	int			x;
	int			ix;
	int			y;
	int			iy;
	int			s;
	int			ts;
}				t_goal;

typedef struct	s_position
{
	int			i;
	int			j;
}				t_position;
#endif
