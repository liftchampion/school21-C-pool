/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 03:33:32 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 03:44:56 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strncat(char *dest, char *src, int nb)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = dest;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		i++;
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (ptr);
}
