/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:39:01 by pscott            #+#    #+#             */
/*   Updated: 2019/01/26 19:16:08 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_max(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	struct passwd		*passwd;
	struct group		*group;

	if (!(passwd = getpwuid(filestat->st_uid)))
		return ;
	if (!(group = getgrgid(filestat->st_gid)))
		return ;
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
	if (get_ulen(filestat->st_ino) + 1 > opt->maxp.ino_len)
		opt->maxp.ino_len = get_ulen(filestat->st_ino) + 1;
	if (S_ISCHR(ldir->d_type) || S_ISBLK(ldir->d_type))
		opt->maxp.isdevice = 1;
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
