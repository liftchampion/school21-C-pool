/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion_args.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:00:18 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 18:29:13 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RECURSION_ARGS_H
# define FT_RECURSION_ARGS_H

# include <stdint.h>

typedef struct {
	int8_t		**m;
	int			line_num;
	int			num;
	int			*vars_count;
	int8_t		**answer;
}	t_recursion_args;

#endif
