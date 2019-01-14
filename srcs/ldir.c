/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:26:54 by pscott            #+#    #+#             */
/*   Updated: 2019/01/14 18:48:06 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*create_ldir(const char *path, struct dirent *dirent, t_opt *opt)
{
	t_ldir *ldir;

	if (opt->a == 0 && (ft_strncmp(dirent->d_name, ".", 1) == 0 || ft_strncmp("..", dirent->d_name, 2) == 0))
		return (NULL);
	if (!(ldir = (t_ldir*)malloc(sizeof(t_ldir))))
		ERROR_MEM;
	(void)opt;
	ldir->path = (char*)path;
	ldir->dir_name = dirent->d_name;
	ldir->d_type = dirent->d_type;
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

void		add_ldir(t_ldir **ldir, t_ldir *new, t_opt *opt)
{
	(void)opt;

	if (!new)
		return ;
	if (ft_strcmp(new->dir_name, (*ldir)->dir_name) > 0)
	{
		while ((*ldir)->next && ft_strcmp(new->dir_name, (*ldir)->next->dir_name) > 0)
			*ldir = (*ldir)->next;
		add_right(*ldir, new);
	}
	else
	{
		while ((*ldir)->prev && ft_strcmp(new->dir_name, (*ldir)->next->dir_name) < 0)
			*ldir = (*ldir)->prev;
		add_left(*ldir, new);
	}
}
