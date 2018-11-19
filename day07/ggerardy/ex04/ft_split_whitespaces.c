/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 06:15:23 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/25 08:34:13 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

unsigned int	ft_count_words(char *str)
{
	int c;
	int was_space;

	c = 0;
	was_space = 1;
	while (*str && ft_is_space(*str))
	{
		str++;
	}
	while (*str)
	{
		if (!ft_is_space(*str) && was_space)
			c++;
		was_space = ft_is_space(*str);
		str++;
	}
	return (c);
}

unsigned int	ft_strlen(char *str, int delim_by_spaces)
{
	unsigned int len;

	len = 0;
	while (*str && (!delim_by_spaces || !ft_is_space(*str)))
	{
		len++;
		str++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < size - 1 && !ft_is_space(*src))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src, 0));
}

char			**ft_split_whitespaces(char *str)
{
	char			**strs;
	int				was_space;
	unsigned int	i;

	was_space = 1;
	i = 0;
	strs = (char**)malloc(sizeof(char*) * ft_count_words(str) + 1);
	if (!strs)
		return (0);
	strs[ft_count_words(str)] = 0;
	while (*str)
	{
		if (was_space && !ft_is_space(*str))
		{
			strs[i] = (char*)malloc(sizeof(char) * ft_strlen(str, 1) + 1);
			ft_strlcpy(strs[i++], str, ft_strlen(str, 1) + 1);
		}
		was_space = ft_is_space(*str);
		str++;
	}
	return (strs);
}
