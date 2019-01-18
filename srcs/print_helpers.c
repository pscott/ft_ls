/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:59:55 by pscott            #+#    #+#             */
/*   Updated: 2019/01/18 21:28:06 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_elle(t_ldir *ldir, t_opt *opt)
{
	struct stat	filestat;

	print_total(ldir, &filestat);
	get_max(ldir, &filestat, opt);
	while (ldir)
	{
		opt_l(ldir, &filestat, opt);
		ldir = ldir->next;
	}
}

void	print_ldir(t_ldir *ldir, t_opt *opt)
{
	if (!ldir)
		return ;
	if (opt->l || opt->o)
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

void	printf_normal(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	if (opt->o)
	{
		printf_normal_o(ldir, filestat, lopt, opt);
	}
	else
	{
		printf_normal_l(ldir, filestat, lopt, opt);
	}
}

void	printf_device(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	if (opt->o)
	{
		printf_device_o(ldir, filestat, lopt, opt);
	}
	else
	{
		printf_device_l(ldir, filestat, lopt, opt);
	}
}
