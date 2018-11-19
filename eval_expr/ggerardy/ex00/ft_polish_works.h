/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polish_works.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:57:27 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:57:28 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POLISH_WORKS_H
# define FT_POLISH_WORKS_H

int				ft_calc_polish(t_list **pol);

t_list			*ft_polish(char *str, int *nums_count);

#endif
