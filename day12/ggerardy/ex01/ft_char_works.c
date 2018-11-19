/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_works.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:05:18 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 23:31:48 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

void		ft_putchar(char c, int where)
{
	write(where, &c, 1);
}

void		ft_putstr(char *str, int where)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], where);
		i++;
	}
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			continue;
		}
		return (*s1 - *s2);
	}
	if (*s1 == *s2)
		return (0);
	if (*s1)
		return (*s1);
	if (*s2)
		return ((-1) * *s2);
	return (0);
}

void		ft_print_error(char *name)
{
	ft_putstr("cat: ", 2);
	ft_putstr(name, 2);
	ft_putstr(": ", 2);
	if (errno == 2)
	{
		ft_putstr("No such file or directory\n", 2);
		return ;
	}
	if (errno == 13)
	{
		ft_putstr("Permission denied\n", 2);
		return ;
	}
	if (errno == 63)
	{
		ft_putstr("File name too long\n", 2);
		return ;
	}
	if (errno == 21)
	{
		ft_putstr("Is a directory\n", 2);
		return ;
	}
}
