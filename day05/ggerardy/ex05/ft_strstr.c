/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:52:23 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 01:46:04 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	char *a;
	char *b;

	b = to_find;
	if (*b == 0)
		return (str);
	while (*str != '\0')
	{
		str++;
		if (*(str - 1) != *b)
			continue;
		a = str - 1;
		while (1)
		{
			if (*b == 0)
				return (str - 1);
			if (*a++ != *b++)
				break ;
		}
		b = to_find;
	}
	return (0);
}
