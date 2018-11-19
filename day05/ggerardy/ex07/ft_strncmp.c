/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:49:45 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 02:14:57 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((*s1 && *s2) && (i++ < n))
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
