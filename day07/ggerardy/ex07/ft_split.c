/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:01:06 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/25 17:26:42 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_is_space(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

unsigned int	ft_count_words(char *str, char *charset)
{
	int c;
	int was_space;

	c = 0;
	was_space = 1;
	while (*str && ft_is_space(*str, charset))
	{
		str++;
	}
	while (*str)
	{
		if (!ft_is_space(*str, charset) && was_space)
			c++;
		was_space = ft_is_space(*str, charset);
		str++;
	}
	return (c);
}

unsigned int	ft_strlen(char *str, int delim_by_spaces, char *charset)
{
	unsigned int len;

	len = 0;
	while (*str && (!delim_by_spaces || !ft_is_space(*str, charset)))
	{
		len++;
		str++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size, char *c)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < size - 1 && !ft_is_space(*src, c))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src, 0, c));
}

char			**ft_split(char *str, char *charset)
{
	char			**strs;
	int				was_space;
	unsigned int	i;
	char			*c;

	c = charset;
	was_space = 1;
	i = 0;
	strs = (char**)malloc(sizeof(char*) * ft_count_words(str, c) + 1);
	if (!strs)
		return (0);
	strs[ft_count_words(str, charset)] = 0;
	while (*str)
	{
		if (was_space && !ft_is_space(*str, charset))
		{
			strs[i] = (char*)malloc(sizeof(char) * ft_strlen(str, 1, c) + 1);
			ft_strlcpy(strs[i++], str, ft_strlen(str, 1, c) + 1, c);
		}
		was_space = ft_is_space(*str, charset);
		str++;
	}
	return (strs);
}
