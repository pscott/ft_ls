/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:59:55 by pscott            #+#    #+#             */
/*   Updated: 2019/01/13 13:15:02 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_opt(t_opt *opt)
{
	ft_printf("\n\t\tOPT\n");
	ft_printf("R: %d\t", opt->rmaj);
	ft_printf("a: %d\t", opt->a);
	ft_printf("l: %d\t", opt->l);
	ft_printf("r: %d\t", opt->r);
	ft_printf("t: %d\n", opt->t);
}

void	print_elle(t_ldir *ldir, t_opt *opt)
{
	(void)opt;
	while (ldir)
	{
		if (ldir->next)
			ft_printf("%s\t", ldir->dir_name);
		else
			ft_printf("%s", ldir->dir_name);
		ldir = ldir->next;
	}
	write(1, "\n\n", 2);
}

void	print_ldir(t_ldir *ldir, t_opt *opt)
{
	if (opt->rmaj)
		print_elle(ldir, opt);
	else
	{
		while (ldir)
		{
			/*		ft_printf("PATH: %-20sDIR_NAME: %-10s  NEXT: %-15p\tPREV: %p\n", ldir->path, ldir->dir_name, ldir->next, ldir->prev);*/
			if (ldir->next)
				ft_printf("%s\t", ldir->dir_name);
			else
				ft_printf("%s", ldir->dir_name);
			ldir = ldir->next;
		}
		write(1, "\n", 1);
	}
}
