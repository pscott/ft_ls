/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:26:54 by pscott            #+#    #+#             */
/*   Updated: 2019/01/18 22:03:23 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_ldir(const char *path, struct dirent *dirent, t_opt *opt)
{
	t_ldir *ldir;

	if (opt->a == 0 && (ft_strncmp(dirent->d_name, ".", 1) == 0
				|| ft_strncmp("..", dirent->d_name, 2) == 0))
		return (NULL);
	if (!(ldir = (t_ldir*)malloc(sizeof(t_ldir))))
		ERROR_MEM;
	ldir->path = ft_strcpy(ft_strnew(ft_strlen((char*)path)), (char*)path);
	ldir->dir_name = ft_strcpy(ft_strnew(ft_strlen(dirent->d_name)),
			dirent->d_name);
	ldir->d_type = dirent->d_type;
	if (ldir->d_type == 4 && ft_strcmp(dirent->d_name, ".")
			&& ft_strcmp("..", dirent->d_name))
		opt->dircount++;
	ldir->next = NULL;
	ldir->prev = NULL;
	return (ldir);
}

void		add_right(t_ldir *a, t_ldir *b)
{
	t_ldir *c;

	if ((c = a->next))
	{
		c->prev = b;
		b->next = c;
	}
	a->next = b;
	b->prev = a;
}

void		add_left(t_ldir *c, t_ldir *b)
{
	t_ldir *a;

	if ((a = c->prev))
	{
		a->next = b;
		b->prev = a;
	}
	c->prev = b;
	b->next = c;
}

void		add_ldir(t_ldir **ldir, t_ldir *new,
		int (*selected_func)(const char *, const char *))
{
	if (!new)
		return ;
	if ((*selected_func)(new->dir_name, (*ldir)->dir_name) > 0)
	{
		while ((*ldir)->next && (*selected_func)(new->dir_name,
					(*ldir)->next->dir_name) > 0)
			*ldir = (*ldir)->next;
		add_right(*ldir, new);
	}
	else
	{
		while ((*ldir)->prev && (*selected_func)(new->dir_name,
					(*ldir)->prev->dir_name) < 0)
			*ldir = (*ldir)->prev;
		add_left(*ldir, new);
	}
}
