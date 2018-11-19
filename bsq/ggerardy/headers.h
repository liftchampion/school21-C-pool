/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:17:01 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/06 11:54:47 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct	s_vec
{
	char		*data;
	uint32_t	len;
	uint32_t	capacity;
}				t_vector;

typedef struct	s_mask
{
	int			num;
	char		empty;
	char		obs;
	char		full;
}				t_mask;

typedef struct	s_sqr
{
	size_t		it;
	size_t		side;
}				t_sq;

typedef	struct	s_intmap
{
	uint16_t	*curr;
	uint16_t	*prev;
	size_t		i;
	size_t		j;
	t_sq		*sq;
}				t_intmap;

int8_t			ft_is_digit(char c);
int				ft_pow(int a, int b);
int				ft_atoi(char *str, uint8_t *it);
t_vector		ft_make_vector();
int8_t			ft_v_push_back(t_vector *v, char c);
void			ft_free_vector(t_vector *v);
int8_t			ft_read_mask(int file, t_mask *mask);
void			ft_copy_data(char *src, char *dest, size_t n);
t_sq			ft_create_sqr(void);
int8_t			ft_check_cool_read(int file, size_t len,
					char *data, t_mask mask);
char			*ft_create_data(int file, size_t *len, t_mask mask);
uint16_t		ft_find_sq(t_mask mask, size_t len, char *data, t_sq *sq);
void			ft_update_map(char *data, t_sq sq, size_t len, t_mask mask);
int8_t			ft_bsq(int file);
t_intmap		create_intmap(size_t len, t_sq *sq);
void			ft_swap(uint16_t **a, uint16_t **b);
int8_t			ft_master(t_intmap *im, char *data, size_t len, t_mask mask);
int8_t			ft_rabotyaga(t_intmap *im, size_t len, t_mask mask, char *data);
int8_t			ft_fill_ones(t_intmap *im, t_mask mask, char *data);
int8_t			ft_parator(t_intmap *im, char *data, size_t len, t_mask mask);

#endif
