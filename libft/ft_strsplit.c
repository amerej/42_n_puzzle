/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:15:29 by aditsch           #+#    #+#             */
/*   Updated: 2018/05/02 23:40:02 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdupi(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		str[i--] = '\0';
		while (i >= 0)
		{
			str[i] = s[i];
			i--;
		}
	}
	return (str);
}

static int	ft_len_words(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;

	str = NULL;
	if (!(s))
		return (str);
	str = (char **)malloc(sizeof(char *) * (ft_len_words(s, c) + 1));
	i = 0;
	j = 0;
	if (!(str))
		return (str);
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			str[j] = ft_strdupi((s + i), c);
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
