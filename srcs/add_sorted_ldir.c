/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sorted_ldir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:55:45 by pscott            #+#    #+#             */
/*   Updated: 2019/01/18 20:23:21 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		choose_c(t_ldir *ldir, t_ldir *new, long *data1, long *data2)
{
	*data1 = ldir->c;
	*data2 = new->c;
}

long		choose_values(t_ldir *ldir, t_ldir *new, t_opt *opt)
{
	long int	data1;
	long int	data2;

	if (opt->u)
	{
		data2 = new->u;
		data1 = ldir->u;
	}
	else if (opt->umaj)
	{
		data2 = new->umaj;
		data1 = ldir->umaj;
	}
	else if (opt->c)
		choose_c(ldir, new, &data1, &data2);
	else
	{
		data2 = new->t;
		data1 = ldir->t;
	}
	if (opt->r)
		return (data2 - data1);
	return (data1 - data2);
}

void		add_sorted_ldir(t_ldir **ldir, t_ldir *new,
		int (*selected_func)(const char *, const char *), t_opt *opt)
{
	if (!new)
		return ;
	if (choose_values((*ldir), new, opt) > 0)
	{
		while ((*ldir)->next && choose_values((*ldir)->next, new, opt) > 0)
			*ldir = (*ldir)->next;
		while ((*ldir)->next && choose_values((*ldir)->next, new, opt) == 0
				&& (*selected_func)(new->dir_name, (*ldir)->next->dir_name) > 0)
			*ldir = (*ldir)->next;
		add_right(*ldir, new);
	}
	else
	{
		while ((*ldir)->prev && choose_values((*ldir)->prev, new, opt) < 0)
			*ldir = (*ldir)->prev;
		while ((*ldir)->prev && choose_values((*ldir)->prev, new, opt) == 0
				&& (*selected_func)(new->dir_name, (*ldir)->prev->dir_name) < 0)
			*ldir = (*ldir)->prev;
		add_left(*ldir, new);
	}
}
