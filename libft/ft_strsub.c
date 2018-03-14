/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 00:58:30 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/17 10:23:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*ret;

	if (!((ret = ft_memalloc(n + 1)) && s))
		return (NULL);
	ft_memcpy(ret, s + start, n);
	return (ret);
}
