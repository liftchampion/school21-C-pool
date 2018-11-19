/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_checks.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:21:39 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/27 13:18:57 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_CHECKS_H
# define FT_SUDOKU_CHECKS_H

# include "t_point.h"
# include <stdint.h>

t_point		ft_get_square(t_point p);

int			ft_check_subsquare(int8_t **m, t_point sq, int value);

int			ft_check_lines(int8_t **m, t_point p, int value);

int			ft_check_insert(int8_t **m, t_point p, int value);

int			ft_check_is_already_in(int8_t **m, int line_num, int num);

#endif
