/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:59:55 by pscott            #+#    #+#             */
/*   Updated: 2019/01/27 12:11:51 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

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

void	print_i(t_ldir *ldir, int max_name)
{
	int				max_ino;
	int				max_col;
	int				max_all;
	struct winsize	ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	max_col = 0;
	max_ino = get_max_ino(ldir);
	max_all = max_ino + 1 + max_name;
	while (ldir->next)
	{
		max_col += max_all;
		if (max_col + max_all >= ws.ws_col)
		{
			max_col = 0;
			ft_printf("%*ld %-*s\n", max_ino, ldir->i,
					max_name, ldir->dir_name);
		}
		else
			ft_printf("%*ld %-*s ", max_ino, ldir->i,
					max_name, ldir->dir_name);
		ldir = ldir->next;
	}
	ft_printf("%lld %s\n", ldir->i, ldir->dir_name);
}

void	print_ldir(t_ldir *ldir, t_opt *opt, int max_name)
{
	int				max_col;
	struct winsize	ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	max_col = 0;
	max_name = get_max_len(ldir);
	(void)opt;
	while (ldir->next)
	{
		max_col += max_name + 1;
		if (max_col + max_name >= ws.ws_col)
		{
			max_col = 0;
			ft_printf("%s\n", ldir->dir_name);
		}
		else
			ft_printf("%-*s ", max_name, ldir->dir_name);
		ldir = ldir->next;
	}
	ft_printf("%-s\n", ldir->dir_name);
}

void	print_select(t_ldir *ldir, t_opt *opt)
{
	int		max_name;

	if (!ldir)
		return ;
	if (opt->l || opt->o)
		print_elle(ldir, opt);
	else
	{
		max_name = get_max_len(ldir);
		if (opt->i)
			print_i(ldir, max_name);
		else
			print_ldir(ldir, opt, max_name);
	}
}
