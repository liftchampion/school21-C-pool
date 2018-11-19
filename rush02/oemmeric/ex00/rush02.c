/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 22:40:32 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/04 22:41:11 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdint.h>


/* 
 *  neither
 *
 *   H|\|Kak0|\|   |b )))
 *
 *    HNKAK0N
 *
 *     H|\|4E|\"0
 *
 *      H1K4K0u*
 *
 *       H14E|"0
 *
 *        H|\|KAK0|\| )))
 *         */

typedef struct
{
	char lu;
	char mu;
	char ru;
	char lm;
	char mm;
	char rm;
	char ld;
	char md;
	char rd;
	int lines;
	int columns;
}       t_pat;


typedef struct
{
	int is_lu;
	int is_ru;
	int is_mu;
	int is_lm;
	int is_mm;
	int is_rm;
	int is_ld;
	int is_md;
	int is_rd;
}   t_pos;


t_pat rush00 = (t_pat){'o', '-', 'o',
	'|', ' ', '|',
	'o', '-', 'o'};

t_pat rush01 = (t_pat){'/',  '*', '\\',
	'*',  ' ', '*',
	'\\',  '*', '/'};

t_pat rush02 = (t_pat){'A', 'B', 'A',
	'B', ' ', 'B',
	'C', 'B', 'C'};

t_pat rush03 = (t_pat){'A', 'B', 'C',
	'B', ' ', 'B',
	'A', 'B', 'C'};

t_pat rush04 = (t_pat){'A', 'B', 'C',
	'B', ' ', 'B',
	'C', 'B', 'A'};



int	ft_rush_cmp(t_pat data, t_pat rush01) // c return
{
	if (data.lu != rush01.lu && data.lu != '\0')
		return (0);
	if (data.mu != rush01.mu && data.mu != '\0')
		return (0);
	if (data.ru != rush01.ru && data.ru != '\0')
		return (0);

	if (data.lm != rush01.lm && data.lm != '\0')
		return (0);
	if (data.mm != rush01.mm && data.mm != '\0')
		return (0);
	if (data.rm != rush01.rm && data.rm != '\0')
		return (0);

	if (data.ld != rush01.ld && data.ld != '\0')
		return (0);
	if (data.md != rush01.md && data.md != '\0')
		return (0);
	if (data.rd != rush01.rd && data.rd != '\0')
		return (0);

	return (1);
}


int ft_upd_patt(char src, char *dest)
{
	if (*dest == '#')
	{
		*dest = src;
		return (1);
	}
	if (*dest == src)
		return (1);
	if (*dest != src)
		return (0);
	return (0);
}

typedef struct
{
	char begin;
	char mid;
	char end;
}       t_str;

typedef struct
{
	int lines;
	int columns;
}   t_size;

typedef struct
{
	char *data;
	int64_t size;
	int64_t capacity;
	int len;
	char last;
}       t_vector;

t_vector ft_make_vector(void)
{
	t_vector v;

	v.data = (char*)malloc(sizeof(char) * 10);
	v.data[0] = 0;
	v.data[1] = 0;
	v.size = 2;
	v.capacity = 10;
	v.len = 0;
	v.last = 0;
	return (v);
}

int ft_push_back(t_vector *vect, char c)
{
	uint64_t i;

	if (vect->size == vect->capacity)
	{
		char *new = (char*)malloc(sizeof(char) * vect->capacity * 2);
		vect->capacity *= 2;
		if (!new)
		{
			return (0);
		}
		i = 0;
		while (i < vect->size)
		{
			new[i] = vect->data[i];
			i++;
		}
		free(vect->data);
		vect->data = new;
	}
	vect->data[vect->size - 2] = c;
	vect->data[vect->size - 1] = 0;
	vect->last = c;
	vect->size++;
	vect->len++;
	return (1);
}

int ft_check_str(t_vector *v)
{
	char c;
	int i;

	if (v->len <= 3)
		return (1);
	c = v->data[1];
	i = 1;
	while (i < v->len - 2)
	{
		if (v->data[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void ft_fill_pattern(t_str s, t_pat *pat, int type, t_size size)
{
	if (type == 1)
	{
		pat->lu = s.begin;
		pat->mu = s.mid;
		pat->ru = s.end;
		return ;
	}
	if (type == 2)
	{
		pat->lm = s.begin;
		pat->mm = s.mid;
		pat->rm = s.end;
		return ;
	}
	if (type == 3)
	{
		pat->ld = s.begin;
		pat->md = s.mid;
		pat->rd = s.end;
		pat->lines = size.lines;
		pat->columns = size.columns;
		return ;
	}
}

t_str ft_get_pattern(t_vector *v)
{
	char c1;
	char c2;
	char c3;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	if (v->len == 2)
		c1 = v->data[0];
	if (v->len == 3)
	{
		c1 = v->data[0];
		c3 = v->data[1];
	}
	if (v->len >= 4)
	{
		c1 = v->data[0];
		c2 = v->data[1];
		c3 = v->data[v->len - 2];
	}
	return ((t_str){c1, c2, c3});
}


int t_str_cmp(t_str s1, t_str s2)
{
	return (s1.begin == s2.begin &&
			s1.mid == s2.mid &&
			s1.end == s2.end);
}


void ft_free_vector(t_vector *v)
{
	free(v->data);
	*v = ft_make_vector();
}

int ft_parse_rush(t_pat *pat)
{
	char b;
	int i;
	int ref_size;
	t_str ref_str;
	t_vector v = ft_make_vector();

	i = 0;
	ref_size = -1;
	while (read(0, &b, 1))
	{
		if (v.last == '\n')
		{
			if (!ft_check_str(&v))
				return (0);
			if (ref_size == -1)
				ref_size = v.len - 1;
			else if (ref_size != v.len - 1)
				return (0);
			if (i == 0)
			{
				ft_fill_pattern(ft_get_pattern(&v), pat, 1, (t_size){0, 0});
				ft_free_vector(&v);
			}
			if (i >= 1)
			{
				if (i == 1)
					ref_str = ft_get_pattern(&v);
				if (t_str_cmp(ref_str, ft_get_pattern(&v)) == 0)
					return (0);
				ft_fill_pattern(ft_get_pattern(&v), pat, 2, (t_size){0, 0});
				ft_free_vector(&v);
			}
			i++;
		}
		ft_push_back(&v, b);
	}
	if (b != '\n')
		ft_push_back(&v, b);    //// (i == 0 ? 1 : 3)
	ft_fill_pattern(ft_get_pattern(&v), pat, 3, (t_size){i, ref_size});
	ft_free_vector(&v);
}

void ft_swap_pat_if_needed(t_pat *pat)
{
	if (pat->lines == 2)
	{
		pat->ld = pat->lm;
		pat->md = pat->mm;
		pat->rd = pat->rm;
		pat->lm = 0;
		pat->mm = 0;
		pat->rm = 0;
		return ;
	}
}


int main(int ac, char **av) {


	t_vector v = ft_make_vector();


	t_pat pat = (t_pat){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	ft_parse_rush(&pat);

	ft_swap_pat_if_needed(&pat);


	return 0;
}
