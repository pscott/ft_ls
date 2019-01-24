/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lreg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:40:14 by pscott            #+#    #+#             */
/*   Updated: 2019/01/24 13:24:42 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_lreg(char *path, t_opt *opt)
{
	struct stat	filestat;
	t_ldir		*lreg;

	if (!(lreg = (t_ldir*)malloc(sizeof(t_ldir))))
		ERROR_MEM;
	lstat(path, &filestat);
	lreg->path = NULL;
	lreg->dir_name = path;
	lreg->d_type = filestat.st_mode;
	if (opt->i)
		lreg->i = filestat.st_ino;
	lreg->next = NULL;
	lreg->prev = NULL;
	return (lreg);
}

void		add_right_and_move(t_ldir **a, t_ldir *b)
{
	(*a)->next = b;
	b->prev = *a;
	*a = (*a)->next;
}

void		print_lreg(t_ldir *lreg, int argc, t_opt *opt)
{
	int			max_name;
	struct stat	filestat;

	if (!lreg)
		return ;
	while (lreg->prev)
		lreg = lreg->prev;
	get_max(lreg, &filestat, opt);
	max_name = get_max_len(lreg);
	if (opt->i && !opt->l)
		print_i(lreg, max_name);
	else
	{
		while (lreg)
		{
			if (opt->l || opt->o)
				opt_l(lreg, &filestat, opt);
			else
				ft_printf("%s%c", lreg->dir_name, lreg->next ? '\t' : '\n');
			lreg = lreg->next;
		}
	}
	if (argc > 0)
		write(1, "\n", 1);
}

void		free_lreg(t_ldir *lreg)
{
	t_ldir *tmp;

	while (lreg)
	{
		tmp = lreg;
		lreg = lreg->next;
		ft_memdel((void*)&tmp);
	}
}
