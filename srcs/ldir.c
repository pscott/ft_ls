/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:26:54 by pscott            #+#    #+#             */
/*   Updated: 2019/01/10 15:59:20 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_ldir(char *path, t_opt *opt)
{
	t_ldir *ldir;

	if (!(ldir = (t_ldir*)malloc(sizeof(t_ldir))))
		EXIT_MEM;
	(void)opt;
	ldir->path = path;
	ldir->next = NULL;
	return (ldir);
}

t_ldir		*add_ldir(t_ldir *ldir, struct dirent *dirent, char *path, t_opt *opt)
{
	t_ldir *tmp;

	tmp = ldir;
	while (ldir->next)
		ldir = ldir->next;
	ldir->next = create_ldir(append_path(path, *d_name), opt);
	return (tmp);
}
