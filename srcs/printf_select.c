/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:48:47 by penzo             #+#    #+#             */
/*   Updated: 2019/01/24 13:24:03 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_printf_elements(char *path, char *time, char *ino, char *symlink)
{
	if (path)
		ft_memdel((void*)&path);
	if (time)
		ft_memdel((void*)&time);
	if (ino && *ino)
		ft_memdel((void*)&ino);
	if (symlink && *symlink)
		ft_memdel((void*)&symlink);
}

void	printf_normal_l(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*ino;
	char	*symlink;
	char	*time;

	ino = opt->i ? ft_ino_itoa(filestat->st_ino) : "";
	path = append_path(ldir->path, ldir->dir_name);
	symlink = get_symlink(ldir, filestat);
	time = get_time(filestat, opt);
	ft_printf("%*s%s%c %*d %-*s  %-*s  %*lld %.12s %s%s\n",
			opt->maxp.ino_len, ino,
			lopt->permi,
			get_attr_char(path),
			opt->maxp.nlink, filestat->st_nlink,
			opt->maxp.owner, lopt->passwd->pw_name,
			opt->maxp.group, lopt->group->gr_name,
			lopt->real_size,
			filestat->st_size,
			time,
			ldir->dir_name, symlink);
	free_printf_elements(path, time, ino, symlink);
}

void	printf_device_l(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*ino;
	char	*symlink;
	char	*time;

	ino = opt->i ? ft_ino_itoa(filestat->st_ino) : "";
	path = append_path(ldir->path, ldir->dir_name);
	symlink = get_symlink(ldir, filestat);
	time = get_time(filestat, opt);
	ft_printf("%*s%s%c %*d %*-s  %*-s  %*d, %*d %.12s %s%s\n",
			opt->maxp.ino_len, ino,
			lopt->permi,
			get_attr_char(path),
			opt->maxp.nlink, filestat->st_nlink,
			opt->maxp.owner, lopt->passwd->pw_name,
			opt->maxp.group, lopt->group->gr_name,
			opt->maxp.major, ft_major(filestat->st_rdev),
			opt->maxp.minor, ft_minor(filestat->st_rdev),
			time,
			ldir->dir_name, symlink);
	free_printf_elements(path, time, ino, symlink);
}

void	printf_normal_o(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*ino;
	char	*symlink;
	char	*time;

	path = append_path(ldir->path, ldir->dir_name);
	ino = opt->i ? ft_ino_itoa(filestat->st_ino) : "";
	symlink = get_symlink(ldir, filestat);
	time = get_time(filestat, opt);
	ft_printf("%*s%s%c %*d %*-s  %*lld %.12s %s%s\n",
			opt->maxp.ino_len, ino,
			lopt->permi,
			get_attr_char(path),
			opt->maxp.nlink, filestat->st_nlink,
			opt->maxp.owner, lopt->passwd->pw_name,
			lopt->real_size,
			filestat->st_size,
			time,
			ldir->dir_name, symlink);
	free_printf_elements(path, time, ino, symlink);
}

void	printf_device_o(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt)
{
	char	*path;
	char	*ino;
	char	*symlink;
	char	*time;

	path = append_path(ldir->path, ldir->dir_name);
	ino = opt->i ? ft_ino_itoa(filestat->st_ino) : "";
	symlink = get_symlink(ldir, filestat);
	time = get_time(filestat, opt);
	ft_printf("%*s%s%c %*d %*-s  %*d, %*d %.12s %s%s\n",
			opt->maxp.ino_len, ino,
			lopt->permi,
			get_attr_char(path),
			opt->maxp.nlink, filestat->st_nlink,
			opt->maxp.owner, lopt->passwd->pw_name,
			opt->maxp.major, ft_major(filestat->st_rdev),
			opt->maxp.minor, ft_minor(filestat->st_rdev),
			time,
			ldir->dir_name, symlink);
	free_printf_elements(path, time, ino, symlink);
}
