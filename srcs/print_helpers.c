/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:59:55 by pscott            #+#    #+#             */
/*   Updated: 2019/01/18 23:14:04 by pscott           ###   ########.fr       */
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

int		get_max_ino(t_ldir *ldir)
{
	int max;
	int	this_len;

	max = 0;
	while (ldir)
	{
		this_len = get_llen(ldir->i);
		if (this_len > max)
			max = this_len;
		ldir = ldir->next;
	}
	return (max);
}

int		get_max_len(t_ldir *ldir)
{
	int max;
	int	this_len;

	max = 0;
	while (ldir)
	{
		this_len = ft_strlen(ldir->dir_name);
		if (this_len > max)
			max = this_len;
		ldir = ldir->next;
	}
	return (max);
}

void	print_i(t_ldir *ldir, int max_name)
{
	int		max_ino;

	max_ino = get_max_ino(ldir);
	while (ldir->next)
	{
		ft_printf("%*ld %-*s\t", max_ino, ldir->i,
				max_name, ldir->dir_name);
		ldir = ldir->next;
	}
	ft_printf("%*ld %-*s\n", max_ino, ldir->i,
			max_name, ldir->dir_name);
}

void	print_ldir(t_ldir *ldir, t_opt *opt)
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
		{
			while (ldir->next)
			{
				ft_printf("%-*s\t", max_name, ldir->dir_name);
				ldir = ldir->next;
			}
			ft_printf("%-*s\n", max_name, ldir->dir_name);
		}
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
