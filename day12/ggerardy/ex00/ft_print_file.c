/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 05:38:40 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 07:53:15 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <zconf.h>
#include <fcntl.h>

#define SIZE 42

void		ft_read_file(char *name)
{
	int			file;
	char		buffer[SIZE];
	int			finished;
	ssize_t		res_of_read;

	finished = 0;
	file = open(name, O_RDONLY);
	if (file == -1)
		return ;
	while (!finished)
	{
		res_of_read = read(file, buffer, SIZE);
		if (res_of_read == -1)
			return ;
		write(1, buffer, (size_t)res_of_read);
		if (res_of_read != SIZE)
			finished = 1;
	}
	close(file);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	ft_read_file(argv[1]);
	return (0);
}
