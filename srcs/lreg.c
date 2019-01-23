/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lreg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*   Created: 2019/01/19 17:56:40 by pscott            #+#    #+#             */
/*   Updated: 2019/01/19 19:33:52 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_lreg(char *path, t_opt *opt)
{
	struct stat	filestat;
	t_ldir		*lreg;

	if (!(lreg =  (t_ldir*)malloc(sizeof(t_ldir))))
		ERROR_MEM;
	stat(path, &filestat);
	lreg->path = NULL; //ft_strcpy(ft_strnew(1), "");
	lreg->dir_name = path;
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
	int max_name;

	if (!lreg)
		return ;
	while (lreg->prev)
		lreg = lreg->prev;
	/*TODO:	if (opt->l || opt->o)
		print_special_l(lreg, opt);*/
	max_name = get_max_len(lreg);
	if (opt->i)
		print_i(lreg, max_name);
	else
	{
		while (lreg->next)
		{
			ft_printf("%s\t", lreg->dir_name);
			lreg = lreg->next;
		}
		ft_printf("%s\n", lreg->dir_name);
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
