/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:47:32 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/01 18:22:14 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

# include "libft.h"

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

typedef struct			s_heap
{
	void				*data;
	size_t				data_size;
	struct s_heap		*next;
}						t_heap;

t_stack					*stack_new_node(void const *data, size_t data_size);
int						stack_is_empty(t_stack *head);
int						stack_push(t_stack **head, void const *data,
							size_t data_size);
void					*stack_pop(t_stack **head);

t_heapp					*heapp_new_node(void const *data, int priority,
							size_t data_size);
int						heapp_is_empty(t_heapp *head);
int						heapp_push(t_heapp **root, void const *data,
							int priority, size_t data_size);
void					*heapp_pop(t_heapp **head);
int						heapp_size(t_heapp *head);

t_heap					*heap_new_node(void const *data, size_t data_size);
int						heap_is_empty(t_heap *heap);
int						heap_push(t_heap **head, void const *data,
							size_t data_size);
void					*heap_pop(t_heap **head);
#endif
