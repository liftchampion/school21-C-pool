/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_works.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:48:38 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 22:51:30 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_WORKS_H
# define FT_FILE_WORKS_H

# include <stdint.h>

uint64_t		ft_get_file_size(char *name);

void			ft_print_file(int file);

int				ft_check_file(char *name);

#endif
