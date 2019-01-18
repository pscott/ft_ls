/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_forest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:48:47 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 20:48:56 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printf_normal_l(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*symlink;

	path = append_path(ldir->path, ldir->dir_name);
	symlink = get_symlink(ldir, filestat);
	ft_printf("%s%c %*d %*-s  %*-s  %*lld %.12s %s%s\n", lopt->permi,
		get_attr_char(path),
		opt->maxp.nlink, filestat->st_nlink,
		opt->maxp.owner, lopt->passwd->pw_name,
		opt->maxp.group, lopt->group->gr_name,
		lopt->real_size,
		filestat->st_size,
		get_time(filestat->st_mtime),
		ldir->dir_name, symlink);
	if (path)
		ft_memdel((void*)&path);
	if (symlink && *symlink)
		ft_memdel((void*)&symlink);
}

void	printf_device_l(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*symlink;

	path = append_path(ldir->path, ldir->dir_name);
	symlink = get_symlink(ldir, filestat);
	ft_printf("%s%c %*d %*-s  %*-s  %*d, %*d %.12s %s%s\n", lopt->permi,
		get_attr_char(path),
		opt->maxp.nlink, filestat->st_nlink,
		opt->maxp.owner, lopt->passwd->pw_name,
		opt->maxp.group, lopt->group->gr_name,
		opt->maxp.major, ft_major(filestat->st_rdev),
		opt->maxp.minor, ft_minor(filestat->st_rdev),
		get_time(filestat->st_mtime),
		ldir->dir_name, symlink);
	if (path)
		ft_memdel((void*)&path);
	if (symlink && *symlink)
		ft_memdel((void*)&symlink);
}

void	printf_normal_o(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*symlink;

	path = append_path(ldir->path, ldir->dir_name);
	symlink = get_symlink(ldir, filestat);
	ft_printf("%s%c %*d %*-s  %*lld %.12s %s%s\n", lopt->permi,
		get_attr_char(path),
		opt->maxp.nlink, filestat->st_nlink,
		opt->maxp.owner, lopt->passwd->pw_name,
		lopt->real_size,
		filestat->st_size,
		get_time(filestat->st_mtime),
		ldir->dir_name, symlink);
	if (path)
		ft_memdel((void*)&path);
	if (symlink && *symlink)
		ft_memdel((void*)&symlink);
}

void	printf_device_o(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*symlink;

	path = append_path(ldir->path, ldir->dir_name);
	symlink = get_symlink(ldir, filestat);
	ft_printf("%s%c %*d %*-s  %*d, %*d %.12s %s%s\n", lopt->permi,
		get_attr_char(path),
		opt->maxp.nlink, filestat->st_nlink,
		opt->maxp.owner, lopt->passwd->pw_name,
		opt->maxp.major, ft_major(filestat->st_rdev),
		opt->maxp.minor, ft_minor(filestat->st_rdev),
		get_time(filestat->st_mtime),
		ldir->dir_name, symlink);
	if (path)
		ft_memdel((void*)&path);
	if (symlink && *symlink)
		ft_memdel((void*)&symlink);
}
