/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:25:53 by penzo             #+#    #+#             */
/*   Updated: 2019/01/13 15:29:10 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	opt_l(t_ldir *ldir, t_opt *opt)
{
	struct stat	filestat;
	char		permi[11];

	(void)opt;
	stat(ldir->path, &filestat);//TODO: protect

		while (ldir)
		{
			//S_ISDIR(filestat.st_mode) ? (permi[0] = 'd') : (permi[0] = '-');
			(ldir->d_type == 4) ? (permi[0] = 'd') : (permi[0] = '-');
			(filestat.st_mode & S_IRUSR) ? (permi[1] = 'r') : (permi[1] = '-');
			(filestat.st_mode & S_IWUSR) ? (permi[2] = 'w') : (permi[2] = '-');
			(filestat.st_mode & S_IXUSR) ? (permi[3] = 'x') : (permi[3] = '-');
			(filestat.st_mode & S_IRGRP) ? (permi[4] = 'r') : (permi[4] = '-');
			(filestat.st_mode & S_IWGRP) ? (permi[5] = 'w') : (permi[5] = '-');
			(filestat.st_mode & S_IXGRP) ? (permi[6] = 'x') : (permi[6] = '-');
			(filestat.st_mode & S_IROTH) ? (permi[7] = 'r') : (permi[7] = '-');
			(filestat.st_mode & S_IWOTH) ? (permi[8] = 'w') : (permi[8] = '-');
			(filestat.st_mode & S_IXOTH) ? (permi[9] = 'x') : (permi[9] = '-');
			permi[10] = 0;
			ft_printf("%s %-10s\n", permi, ldir->dir_name);
			//ft_printf("PATH: %-10s  DIR_NAME: %-10s  NEXT: %p\n", ldir->path, ldir->dir_name, ldir->next);
			ldir = ldir->next;
		}

}
