/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:59:55 by pscott            #+#    #+#             */
/*   Updated: 2019/01/16 19:17:20 by pscott           ###   ########.fr       */
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
}

void	print_ldir(t_ldir *ldir, t_opt *opt)
{
	if (!ldir)
		return ;
	if (opt->l)
		print_elle(ldir, opt);
	else
	{
		while (ldir->next)
		{
			ft_printf("%s\t", ldir->dir_name);
			ldir = ldir->next;
		}
		ft_printf("%s\n", ldir->dir_name);
	}
}
