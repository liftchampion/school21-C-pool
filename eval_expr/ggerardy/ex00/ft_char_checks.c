/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:55:53 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:55:55 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		ft_is_op(char c)
{
	if ((c >= '(' && c <= '+') ||
	c == '-' || c == '/' || c == '%')
		return (1);
	return (0);
}

int		ft_is_unary_minus(char *str, int it)
{
	if (str[it] && str[it] == '-')
	{
		if (str[it + 1] && ft_is_digit(str[it + 1]))
		{
			return (1);
		}
	}
	return (0);
}

int		ft_is_left_ass(char c)
{
	if (c == '-' || c == '/' || c == '%')
		return (1);
	return (0);
}
