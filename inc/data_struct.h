/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 08:05:56 by aditsch           #+#    #+#             */
/*   Updated: 2018/03/19 08:11:15 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "../libft/libft.h"

typedef struct			s_stack
{
	void				*data;
	size_t				data_size;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_heapp
{
	void				*data;
	size_t				data_size;
	int					priority;
	struct s_heapp		*next;
}						t_heapp;

t_stack					*stack_new_node(void const *data, size_t data_size);
int						stack_is_empty(t_stack *root);
int						stack_push(t_stack **root, void const *data, size_t data_size);
void					*stack_pop(t_stack **root);

t_heapp					*heapp_new_node(void const *data, int priority, size_t data_size);
int						heapp_is_empty(t_heapp *head);
int						heapp_push(t_heapp **root, void const *data, int priority, size_t data_size);
void					*heapp_pop(t_heapp **head);
#endif