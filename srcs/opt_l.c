/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:25:53 by penzo             #+#    #+#             */
/*   Updated: 2019/01/17 17:58:24 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filetypeletter(t_ldir *ldir, int stat)
{
	char	c;
	(void)stat;

	c = 0;
	//c = '-';//8 = regular file
	c = ldir->d_type == 1 ? 'p' : c;//character devices
	c = ldir->d_type == 2 ? 'c' : c;//character devices
	c = ldir->d_type == 4 ? 'd' : c;//directories
	c = ldir->d_type == 6 ? 'b' : c;//block devices
	c = ldir->d_type == 8 ? '-' : c;//ordinaty files
	c = ldir->d_type == 10 ? 'l' : c;//symlink
	return (c);
}

char	*get_permi(t_ldir *ldir, int stat)
{
	static char	bits[11];
	static const char *rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x",
		"rw-", "rwx"};

	bits[0] = filetypeletter(ldir, stat);
	ft_strcpy(&bits[1], rwx[(stat >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(stat >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(stat & 7)]);
	bits[10] = 0;
	return (bits);
}

void	get_max(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	struct passwd		*passwd;
	struct group		*group;

	opt->maxp.nlink = 3;
	opt->maxp.owner = 0;
	opt->maxp.group = 5;
	opt->maxp.size = 3;
	while (ldir)
	{
		passwd = getpwuid(filestat->st_uid);
		group = getgrgid(filestat->st_gid);
		stat(append_path(ldir->path, ldir->dir_name, opt), filestat);//TODO: protect
		if (ft_strlen(ft_itoa(filestat->st_nlink)) > opt->maxp.nlink)//nlink
			opt->maxp.nlink = ft_strlen(ft_itoa(filestat->st_nlink));
		if (ft_strlen(passwd->pw_name) > opt->maxp.owner)//owner
			opt->maxp.owner = ft_strlen(passwd->pw_name);
		if (ft_strlen(group->gr_name) > opt->maxp.group)//group
			opt->maxp.group = ft_strlen(group->gr_name);
		if (ft_strlen(ft_itoa(filestat->st_size)) > opt->maxp.size)//size
			opt->maxp.size = ft_strlen(ft_itoa(filestat->st_size));
		ldir = ldir->next;
	}
}

void	print_total(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	int		blocks_used;

	blocks_used = 0;
	while(ldir)
	{

		if (lstat(append_path(ldir->path, ldir->dir_name, opt), filestat) == -1)//TODO: protect
			ft_printf("error, %s\n", ldir->dir_name);//TODO
		blocks_used += filestat->st_blocks;
		ldir = ldir->next;
	}
	ft_printf("total %d\n", blocks_used);
}
//TODO make /dev work plz !
void	opt_l(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	char				*permi;
	struct passwd		*passwd;
	struct group		*group;

	if (lstat(append_path(ldir->path, ldir->dir_name, opt), filestat) == -1)//TODO: protect
		ft_printf("error, %s\n", ldir->dir_name);//TODO
	permi = get_permi(ldir, filestat->st_mode);
	passwd = getpwuid(filestat->st_uid);//TODO: if getpwuid fail, print numeric ID
	group = getgrgid(filestat->st_gid);//TODO: - same -
	//if getuid fail, redirect to another printf
	//if ldir->d_type == 2/6, redirect
	ft_printf("%s%c%*d %*s  %*-s  %*lld %.12s %s%s\n", permi,
			get_attr_char(append_path(ldir->path, ldir->dir_name, opt)),
			opt->maxp.nlink, filestat->st_nlink, opt->maxp.owner,
			passwd->pw_name, opt->maxp.group, group->gr_name, opt->maxp.size,
			filestat->st_size, get_time(filestat->st_mtime), ldir->dir_name,
			get_symlink(ldir, filestat, opt));
}
