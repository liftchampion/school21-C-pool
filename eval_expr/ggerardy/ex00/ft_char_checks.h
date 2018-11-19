/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_checks.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:56:06 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:58:51 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_CHECKS_H
# define FT_CHAR_CHECKS_H

int		ft_is_digit(char c);

int		ft_is_space(char c);

int		ft_is_op(char c);

int		ft_is_unary_minus(char *str, int it);

int		ft_is_left_ass(char c);

#endif
