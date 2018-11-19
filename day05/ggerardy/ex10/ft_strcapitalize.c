/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 00:43:54 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 06:56:49 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_delim(char c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
	{
		if (!(c >= '0' && c <= '9'))
			return (1);
	}
	return (0);
}

int			ft_is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int			ft_is_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char		*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		is_prev_delim;

	ptr = str;
	is_prev_delim = 1;
	while (*str)
	{
		if (ft_is_delim(*str))
		{
			is_prev_delim = 1;
		}
		if (is_prev_delim && ft_is_low(*str))
			*str -= 32;
		if (!is_prev_delim && ft_is_up(*str))
			*str += 32;
		if (!ft_is_delim(*str))
		{
			is_prev_delim = 0;
		}
		str++;
	}
	return (ptr);
}
