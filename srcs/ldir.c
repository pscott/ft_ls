/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:26:54 by pscott            #+#    #+#             */
/*   Updated: 2019/01/11 14:46:29 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_ldir(const char *path, struct dirent *dirent, t_opt *opt)
{
	t_ldir *ldir;

	if (opt->a == 0 && (ft_strcmp(dirent->d_name, ".") == 0 || ft_strcmp("..", dirent->d_name) == 0))
		return (NULL);
	if (!(ldir = (t_ldir*)malloc(sizeof(t_ldir))))
		EXIT_MEM;
	(void)opt;
	ldir->path = append_path(path, dirent->d_name, opt);
	ldir->dir_name = dirent->d_name;
	ldir->d_type = dirent->d_type;
	ldir->next = NULL;
	ldir->prev = NULL;
	return (ldir);
}

void		add_right(t_ldir *ldir, t_ldir *new)
{
	ldir->next = new;
	new->prev = ldir;
}

void		add_left(t_ldir *ldir, t_ldir *new)
{
	ldir->prev = new;
	new->next = ldir;
}

void		add_ldir(t_ldir **ldir, t_ldir *new, t_opt *opt)
{
	(void)opt;

	if (!new)
		return ;
	if (ft_strcmp(new->dir_name, (*ldir)->dir_name) > 0)
	{
		while ((*ldir)->next && ft_strcmp(new->dir_name, (*ldir)->dir_name) > 0)
			*ldir = (*ldir)->next;
		add_right(*ldir, new);
	}
	else
	{
		while ((*ldir)->prev && ft_strcmp(new->dir_name, (*ldir)->dir_name) < 0)
			*ldir = (*ldir)->prev;
		add_left(*ldir, new);
	}
}
