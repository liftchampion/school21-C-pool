/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polish_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 03:57:05 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 04:01:00 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POLISH_LIST_H
# define FT_POLISH_LIST_H

typedef struct		s_list
{
	struct s_list	*next;
	int				data;
	char			op;
}					t_list;

#endif
