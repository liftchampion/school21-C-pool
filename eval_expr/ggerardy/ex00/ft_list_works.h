/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_works.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:56:39 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 03:59:53 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_WORKS_H
# define FT_LIST_WORKS_H

t_list		*ft_create_elem(int data, char op);

void		ft_list_push_front(t_list **begin_list, int data, char op);

void		ft_list_pop_push(t_list **ops, t_list **out);

void		ft_list_free_front(t_list **list);

#endif
