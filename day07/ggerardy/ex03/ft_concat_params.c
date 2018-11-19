/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 05:40:42 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/25 06:12:40 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char				*ft_concat_params(int argc, char **argv)
{
	int				i;
	unsigned int	total_len;
	char			*ptr;

	i = 1;
	total_len = 0;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]) + 1;
		i++;
	}
	ptr = (char*)malloc(sizeof(char) * total_len);
	if (!ptr)
		return (ptr);
	i = 1;
	ptr[0] = 0;
	while (i < argc)
	{
		ft_strlcat(ptr, argv[i], total_len);
		if (i != argc - 1)
			ft_strlcat(ptr, "\n", total_len);
		i++;
	}
	return (ptr);
}
