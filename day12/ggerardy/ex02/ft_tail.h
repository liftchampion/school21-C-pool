/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:53:14 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/01 22:54:54 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <stdint.h>

void		ft_tail_plus(char *name, uint64_t n);

void		ft_tail_minus(char *name, uint64_t n);

void		ft_tail(char *name, char mode, uint64_t n);

#endif
