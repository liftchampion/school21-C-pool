/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_works.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:28:37 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 21:21:14 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_WORKS_H
# define FT_MATRIX_WORKS_H

# include <stdint.h>
# include "ft_size.h"

void		ft_print_matrix(int8_t **m);

void		ft_fill_matrix(int8_t **m);

void		ft_fill_data(int8_t **m, char **data);

void		ft_matrix_copy(int8_t **src, int8_t **dest);

#endif
