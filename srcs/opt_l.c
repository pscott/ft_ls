/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:25:53 by penzo             #+#    #+#             */
/*   Updated: 2019/01/27 12:10:41 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total(t_ldir *ldir, struct stat *filestat)
{
	int		blocks_used;
	char	*path;

	blocks_used = 0;
	while (ldir)
	{
		path = append_path(ldir->path, ldir->dir_name);
		if (lstat(path, filestat))
			error_stat();
		free(path);
		blocks_used += filestat->st_blocks;
		ldir = ldir->next;
	}
	ft_printf("total %d\n", blocks_used);
}

void	opt_l(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	struct s_lopt	lopt;
	char			*path;

	if (opt->maxp.isdevice)
		lopt.real_size = opt->maxp.major + opt->maxp.minor + 2;
	else
		lopt.real_size = opt->maxp.size;
	path = append_path(ldir->path, ldir->dir_name);
	if (lstat(path, filestat))
		error_stat();
	lopt.permi = get_permi(ldir, filestat->st_mode);
	errno = 0;
	lopt.passwd = my_getpwuid(lopt.passwd, filestat, opt);
	lopt.group = my_getgrgid(lopt.group, filestat, opt);
	if (!opt->i)
		opt->maxp.ino_len = 0;
	if (S_ISCHR(ldir->d_type) || S_ISBLK(ldir->d_type))
		printf_device(ldir, filestat, &lopt, opt);
	else
		printf_normal(ldir, filestat, &lopt, opt);
	free(path);
	if (lopt.permi && opt->is_alloc)
		ft_memdel((void*)&lopt.permi);
	if (lopt.group && opt->is_alloc)
		ft_memdel((void*)&lopt.group);
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
