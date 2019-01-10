/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:26:54 by pscott            #+#    #+#             */
/*   Updated: 2019/01/10 19:02:49 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_ldir(const char *path, struct dirent *dirent, t_opt *opt)
{
	t_ldir *ldir;

	if (!(ldir = (t_ldir*)malloc(sizeof(t_ldir))))
		EXIT_MEM;
	(void)opt;
	ldir->path = append_path(path, dirent->d_name, opt);
	ldir->dir_name = dirent->d_name;
	ldir->d_type = dirent->d_type;
	ldir->next = NULL;
	return (ldir);
}

void		add_ldir(t_ldir *ldir, t_ldir *new)
{
	if (ldir == NULL)
	{
		ldir = new;
		return ;
	}
	while (ldir->next)
		ldir = ldir->next;
	ldir->next = new;
}
