/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:47:32 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:06:57 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_everything(t_ls *ls)
{
	t_ldir *tmp;

	if (ls)
	{
		if (ls->opt)
			free(ls->opt);
		if (ls->ldir)
		{
			while (ls->ldir->next)
			{
				tmp = ls->ldir;
				if (ls->ldir->path)
					free(ls->ldir->path);
				ls->ldir = ls->ldir->next;
				free(tmp);
			}
			if (ls->ldir->path)
				free(ls->ldir->path);
			free(ls->ldir);
		}
		free(ls);
	}
	return (0);
}
