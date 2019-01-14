/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:25:53 by penzo             #+#    #+#             */
/*   Updated: 2019/01/14 18:21:01 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		filetypeletter(t_ldir *ldir, int stat)
{
	char	c;
	(void)stat;

	(ldir->d_type == 4) ? (c = 'd') : (c = '-');
	return (c);
}

char	*bitwise(t_ldir *ldir, int stat)
{
	static char	bits[11];
	static const char *rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};

	//printf("name: %s\n", ldir->dir_name);
	bits[0] = filetypeletter(ldir, stat);
	strcpy(&bits[1], rwx[(stat >> 6) & 7]);
	strcpy(&bits[4], rwx[(stat >> 3) & 7]);
	strcpy(&bits[7], rwx[(stat & 7)]);
	bits[10] = 0;
	return (bits);
}

void	get_max(t_ldir *ldir, struct stat filestat, t_opt *opt)
{
	struct passwd		*passwd;
	struct group		*group;

	opt->maxp.nlink = 2;
	opt->maxp.owner = 0;
	opt->maxp.group = 11;
	opt->maxp.size = 3;
	while (ldir)
	{
		passwd = getpwuid(filestat.st_uid);
		group = getgrgid(filestat.st_gid);
		stat(append_path(ldir->path, ldir->dir_name, opt), &filestat);//TODO: protect
		if (ft_strlen(ft_itoa(filestat.st_nlink)) > opt->maxp.nlink)//nlink
			opt->maxp.nlink = ft_strlen(ft_itoa(filestat.st_nlink));
		if (ft_strlen(passwd->pw_name) > opt->maxp.owner)//owner
			opt->maxp.owner = ft_strlen(passwd->pw_name);
		if (ft_strlen(group->gr_name) > opt->maxp.group)//group
			opt->maxp.group = ft_strlen(group->gr_name);
		if (ft_strlen(ft_itoa(filestat.st_size)) > opt->maxp.size)//size
			opt->maxp.size = ft_strlen(ft_itoa(filestat.st_size));
		if (ft_strlen(ft_itoa(filestat.st_nlink)) > opt->maxp.nlink)//file_name
			opt->maxp.nlink = ft_strlen(ft_itoa(filestat.st_nlink));
		ldir = ldir->next;
	}
}

void	opt_l(t_ldir *ldir, t_opt *opt)
{
	struct stat			filestat;
	char				*permi;
	struct passwd		*passwd;
	struct group		*group;

	//(void)opt;
	//get max size of each ldir_comp
	stat(append_path(ldir->path, ldir->dir_name, opt), &filestat);//just one time
	get_max(ldir, filestat, opt);
	while (ldir)
	{
		if (stat(append_path(ldir->path, ldir->dir_name, opt), &filestat) == -1)//TODO: protect
		{
			printf("error, %s\n", ldir->dir_name);//TODO
		}
		permi = bitwise(ldir, filestat.st_mode);
		passwd = getpwuid(filestat.st_uid);
		group = getgrgid(filestat.st_gid);
		ft_printf("%s %*d %*s %*s %*lld %s\n", permi, opt->maxp.nlink, filestat.st_nlink, opt->maxp.owner, passwd->pw_name, opt->maxp.group, group->gr_name, opt->maxp.size, filestat.st_size, ldir->dir_name);
		//ft_printf("%s %10d %10s %10lld %s\n", permi, filestat.st_nlink, passwd->pw_name, filestat.st_size, ldir->dir_name);
		ldir = ldir->next;
	}
}
