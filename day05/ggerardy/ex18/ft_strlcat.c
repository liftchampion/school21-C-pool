/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 04:17:41 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/23 06:43:26 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dest_len;
	unsigned int src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (*dest && i < size)
	{
		i++;
		dest++;
	}
	dest_len = i;
	while (*src && i < size - 1)
	{
		i++;
		*dest = *src;
		src++;
		dest++;
	}
	if (i < size)
		*dest = '\0';
	return (dest_len + src_len);
}
