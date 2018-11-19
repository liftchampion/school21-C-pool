/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:04:29 by ggerardy          #+#    #+#             */
/*   Updated: 2018/10/28 20:59:31 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_INPUT_H
# define FT_CHECK_INPUT_H

# include <stdint.h>

int		ft_check_str(char *str);

int		ft_check_args(int ac, char **av);

int		ft_check_is_valid(int8_t **m);

#endif
