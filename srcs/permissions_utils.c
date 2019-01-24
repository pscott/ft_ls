/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:19:35 by penzo             #+#    #+#             */
/*   Updated: 2019/01/24 11:26:17 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_maxp(t_opt *opt)
{
	opt->maxp.nlink = 1;
	opt->maxp.owner = 0;
	opt->maxp.group = 5;
	opt->maxp.size = 0;
	opt->maxp.major = 0;
	opt->maxp.minor = 0;
	opt->maxp.isdevice = 0;
	opt->maxp.ino_len = 0;
}

int		filetypeletter(t_ldir *ldir)
{
	char	c;

	if (S_ISREG(ldir->d_type))
		c = '-';
	else if (S_ISDIR(ldir->d_type))
		c = 'd';
	else if (S_ISBLK(ldir->d_type))
		c = 'b';
	else if (S_ISCHR(ldir->d_type))
		c = 'c';
	else if (S_ISFIFO(ldir->d_type))
		c = 'p';
	else if (S_ISLNK(ldir->d_type))
		c = 'l';
	else if (S_ISSOCK(ldir->d_type))
		c = 's';
	else
		c = '?';
	return(c);
}

char	*get_permi(t_ldir *ldir, int stat)
{
	static char			bits[11];
	static const char	*rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x",
		"rw-", "rwx"};

	bits[0] = filetypeletter(ldir);
	ft_strcpy(&bits[1], rwx[(stat >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(stat >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(stat & 7)]);
	bits[10] = 0;
	if (stat & S_ISVTX)//degueu, il y a certainement d'autre cas, mais osef d'apres le sujet
		bits[9] = 't';
	return (bits);
}
