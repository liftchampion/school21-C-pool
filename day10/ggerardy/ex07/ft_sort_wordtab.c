/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:32:55 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 11:34:08 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (tab[i])
	{
		tmp = tab[i];
		j = i;
		while (j > 0 && ft_strcmp(tab[j - 1], tmp) > 0)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
		i++;
	}
}
