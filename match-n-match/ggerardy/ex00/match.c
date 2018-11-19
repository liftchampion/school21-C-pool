/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:41:49 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 23:39:59 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
 

int ft_strlen(char *str, int delim_by_stars)
{
	int len;

	len = 0;
	while (str[len] && (!delim_by_stars || str[len] != '*'))
	{
		len++;
	}
	return (len);
}

int ft_strfind(char *str, char *to_find, int start)
{
	int i;
	int j;
	int k;

	j = 0;
	i = start;
	if (to_find[j] == 0)
		return (0);
	while (str[i] != '\0')
	{
		i++;
		if (str[i - 1] != to_find[j])
			continue;
		k = i - 1;
		while (1)
		{
			if (to_find[j] == 0 || to_find[j] == '*')
				return (i - 1);
			if (str[k++] != to_find[j++])
				break ;
		}
		j = 0;
	}
	return (-1);
}

int ft_count_words(char *str)
{
	int was_space;
	int count;

	was_space = 1;
	count = 0;
	while (*str && *str == '*')
		str++;
	while (*str)
	{
		if (was_space && *str != '*')
			count++;
		was_space = (*str == '*');
		str++;
	}
	return (count);
}

char *ft_get_word(char *str, int num)
{
	int i;
	int was_space;

	i = -1;
	was_space = 1;
	while (*str && *str == '*')
		str++;
	while (*str)
	{
		if (was_space && *str != '*')
		{
			i++;
			if (i == num)
				return (str);
		}
		was_space = (*str == '*');
		str++;
	}
	return (str);
}


void ft_recursion(char *s1, char *s2, int pos, int word_num, int words_count, int *vars)
{
	int i;
	int f;

	i = pos;
	if (word_num == words_count)
	{
		(*vars)++;
		return ;
	}

	while (i < ft_strlen(s1, 0))
	{
		f = ft_strfind(s1, ft_get_word(s2, word_num), pos);
		if (f != -1)
		{
			ft_recursion(s1, s2, f + ft_strlen(ft_get_word(s2, word_num), 1), word_num + 1, words_count, vars);
		}
		i++;
	}
}


int match(char *s1, char *s2)
{
	int words_count;
	int vars = 0;

	if (*s2 != '*' && *s2 != *s1)
		return (0);
	if (s2[ft_strlen(s2, 0) - 1] != '*' && s2[ft_strlen(s2, 0) - 1] != s1[ft_strlen(s1, 0) - 1])
		return (0);
	words_count = ft_count_words(s2);
	ft_recursion(s1, s2, 0, 0, words_count, &vars);
	return (vars != 0);
}
