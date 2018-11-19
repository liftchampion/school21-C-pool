/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:10:54 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/24 23:20:35 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
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

int			ft_sort_strings(char *strs[], int size)
{
	int		i;
	int		j;
	char	*tmp;
	int		was_changed;

	i = 1;
	was_changed = 0;
	while (i < size)
	{
		tmp = strs[i];
		j = i;
		while (j > 0 && ft_strcmp(strs[j - 1], tmp) > 0)
		{
			was_changed = 1;
			strs[j] = strs[j - 1];
			j--;
		}
		strs[j] = tmp;
		i++;
	}
	return (was_changed);
}

int			main(int argc, char *argv[])
{
	int i;
	int w;

	i = 0;
	w = 1;
	argv++;
	while (w)
		w = ft_sort_strings(argv, argc - 1);
	while (i < argc - 1)
	{
		ft_putstr(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
