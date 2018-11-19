/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polish_works_helper.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:57:39 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:57:42 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POLISH_WORKS_HELPER_H
# define FT_POLISH_WORKS_HELPER_H

int			ft_get_priority(char c);

int			ft_need_pop(t_list *ops, char op);

int			ft_do_op_math(int a, int b, char op);

int			ft_do_op_list(t_list *prev, t_list *op, int is_fin);

void		ft_handle_op(t_list **ops, t_list **out, char op);

#endif
