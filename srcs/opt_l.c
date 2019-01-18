/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:25:53 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 13:24:43 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filetypeletter(t_ldir *ldir, int stat)
{
	char	c;
	(void)stat;

	c = 0;
	//c = '-';//8 = regular file
	c = ldir->d_type == 0 ? 'd' : c;//Degueu
	c = ldir->d_type == 1 ? 'p' : c;//FIFO
	c = ldir->d_type == 2 ? 'c' : c;//character devices
	c = ldir->d_type == 4 ? 'd' : c;//directories
	c = ldir->d_type == 6 ? 'b' : c;//block devices
	c = ldir->d_type == 8 ? '-' : c;//ordinaty files
	c = ldir->d_type == 10 ? 'l' : c;//symlink
	c = ldir->d_type == 12 ? 's' : c;//socket
	return (c);
}
int		max_a_b(int a, int b)
{
	if (a > b || a == b)
		return (a);
	else
		return (b);
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
	if (stat & S_ISVTX)//degueu, il y a certainement d'autre cas
		bits[9] = 't';
	return (bits);
}

void	get_max(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	struct passwd		*passwd;
	struct group		*group;

	init_maxp(opt);
	while (ldir)
	{
		passwd = getpwuid(filestat->st_uid);
		group = getgrgid(filestat->st_gid);
		lstat(append_path(ldir->path, ldir->dir_name, opt), filestat);//TODO: protect
		if (ft_strlen(ft_itoa(filestat->st_nlink)) > opt->maxp.nlink)//nlink
			opt->maxp.nlink = ft_strlen(ft_itoa(filestat->st_nlink));
		if (ft_strlen(passwd->pw_name) > opt->maxp.owner)//owner
			opt->maxp.owner = ft_strlen(passwd->pw_name);
		if (ft_strlen(group->gr_name) > opt->maxp.group)//group
			opt->maxp.group = ft_strlen(group->gr_name);
		if (ft_strlen(ft_itoa(filestat->st_size)) > opt->maxp.size)//size
			opt->maxp.size = ft_strlen(ft_itoa(filestat->st_size));
		if (ft_strlen(ft_itoa(ft_major(filestat->st_rdev))) > opt->maxp.major)//major
			opt->maxp.major = ft_strlen(ft_itoa(ft_major(filestat->st_rdev)));/////////
		if (ft_strlen(ft_itoa(ft_minor(filestat->st_rdev))) > opt->maxp.minor)//minor
			opt->maxp.minor = ft_strlen(ft_itoa(ft_minor(filestat->st_rdev)));
		if (ldir->d_type == 2 || ldir->d_type == 6)
			opt->maxp.isdevice = 1;
		//printf("len:%zu max:%d nlink:%d\n", ft_strlen(ft_itoa(filestat->st_nlink)), opt->maxp.nlink, filestat->st_nlink);
		ldir = ldir->next;
	}
	if (opt->maxp.isdevice == 1)
		opt->maxp.major++;
	//printf("nlink: %d\n", opt->maxp.nlink);
	//printf("max: %d\n", max_a_b(opt->maxp.major + opt->maxp.minor, opt->maxp.size));
	//printf("major: %d, minor: %d, size: %d\n", opt->maxp.major, opt->maxp.minor, opt->maxp.size);
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
	unsigned int		real_size;

	if (opt->maxp.isdevice)
		real_size = opt->maxp.major + opt->maxp.minor + 2;
	else
		real_size = opt->maxp.size;
	if (lstat(append_path(ldir->path, ldir->dir_name, opt), filestat) == -1)//TODO: protect
		ft_printf("error, %s\n", ldir->dir_name);//TODO
	permi = get_permi(ldir, filestat->st_mode);
	passwd = getpwuid(filestat->st_uid);//TODO: if getpwuid fail, print numeric ID
	group = getgrgid(filestat->st_gid);//TODO: - same -
	//if getuid fail, redirect to another printf
	if (ldir->d_type == 2 || ldir->d_type == 6)//devices
		ft_printf("%s%c %*d %*-s  %*-s  %*d, %*d %.12s %s%s\n", permi,
			get_attr_char(append_path(ldir->path, ldir->dir_name, opt)),
			opt->maxp.nlink, filestat->st_nlink,
			opt->maxp.owner, passwd->pw_name,
			opt->maxp.group, group->gr_name,
			opt->maxp.major, ft_major(filestat->st_rdev),
			opt->maxp.minor, ft_minor(filestat->st_rdev),
			get_time(filestat->st_mtime),
			ldir->dir_name, get_symlink(ldir, filestat, opt));
	else
	{
		ft_printf("%s%c %*d %*-s  %*-s  %*lld %.12s %s%s\n", permi,
			get_attr_char(append_path(ldir->path, ldir->dir_name, opt)),
			opt->maxp.nlink, filestat->st_nlink,
			opt->maxp.owner, passwd->pw_name,
			opt->maxp.group, group->gr_name,
			//opt->maxp.major + opt->maxp.minor + 2,
			//opt->maxp.major + opt->maxp.minor,
			//max_a_b(opt->maxp.major + opt->maxp.minor, opt->maxp.size),
			real_size,
			filestat->st_size,
			get_time(filestat->st_mtime),
			ldir->dir_name, get_symlink(ldir, filestat, opt));
	}
}
