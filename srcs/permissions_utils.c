/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:19:35 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 21:20:07 by penzo            ###   ########.fr       */
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
}

int		filetypeletter(t_ldir *ldir, int stat)
{
	char	c;

	(void)stat;
	c = 0;
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

char	*get_permi(t_ldir *ldir, int stat)
{
	static char			bits[11];
	static const char	*rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x",
		"rw-", "rwx"};

	bits[0] = filetypeletter(ldir, stat);
	ft_strcpy(&bits[1], rwx[(stat >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(stat >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(stat & 7)]);
	bits[10] = 0;
	if (stat & S_ISVTX)//degueu, il y a certainement d'autre cas, mais osef d'apres le sujet
		bits[9] = 't';
	return (bits);
}
