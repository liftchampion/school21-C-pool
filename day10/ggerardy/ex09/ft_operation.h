/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 06:59:40 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/30 09:45:25 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

typedef void	(*t_operation)(int a, int b);

typedef	struct	s_opp{
	char		*sign;
	t_operation	op;
}				t_opp;

#endif
