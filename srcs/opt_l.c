/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:25:53 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 23:49:38 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_max(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	struct passwd		*passwd;
	struct group		*group;

	passwd = getpwuid(filestat->st_uid);
	group = getgrgid(filestat->st_gid);
	if (get_uhlen(filestat->st_nlink) > opt->maxp.nlink)
		opt->maxp.nlink = get_uhlen(filestat->st_nlink);
	if (ft_strlen(passwd->pw_name) > opt->maxp.owner)
		opt->maxp.owner = ft_strlen(passwd->pw_name);
	if (ft_strlen(group->gr_name) > opt->maxp.group)
		opt->maxp.group = ft_strlen(group->gr_name);
	if ((unsigned int)get_len(filestat->st_size) > opt->maxp.size)
		opt->maxp.size = get_len(filestat->st_size);
	if ((unsigned int)get_len(ft_major(filestat->st_rdev)) > opt->maxp.major)
		opt->maxp.major = get_len(ft_major(filestat->st_rdev));
	if ((unsigned int)get_len(ft_minor(filestat->st_rdev)) > opt->maxp.minor)
		opt->maxp.minor = get_len(ft_minor(filestat->st_rdev));
	if (ldir->d_type == 2 || ldir->d_type == 6)
		opt->maxp.isdevice = 1;
}

void	get_max(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	char	*path;

	init_maxp(opt);
	while (ldir)
	{
		path = append_path(ldir->path, ldir->dir_name);
		if (lstat(path, filestat))
			error_stat();
		set_max(ldir, filestat, opt);
		ft_memdel((void*)&path);
		ldir = ldir->next;
	}
	if (opt->maxp.isdevice == 1)
		opt->maxp.major++;
}

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
	errno = 0;//
	lopt.passwd = my_getpwuid(lopt.passwd, filestat, opt);//THE GOOD ONE
	lopt.group = my_getgrgid(lopt.group, filestat, opt);
	if (ldir->d_type == 2 || ldir->d_type == 6)
		printf_device(ldir, filestat, &lopt, opt);
	else
		printf_normal(ldir, filestat, &lopt, opt);
	free(path);
	if (lopt.permi && opt->is_alloc)
		ft_memdel((void*)&lopt.permi);
	if (lopt.group && opt->is_alloc)
		ft_memdel((void*)&lopt.group);
}
