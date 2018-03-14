/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 01:28:01 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/13 16:36:33 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (!((s1 && s2) && (ret = ft_strnew((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	ft_strcat(ft_strcpy(ret, s1), s2);
	return (ret);
}
