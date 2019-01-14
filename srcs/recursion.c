/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:44:10 by pscott            #+#    #+#             */
/*   Updated: 2019/01/14 19:49:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion(t_ldir *ldir, int *ret, t_opt *opt)
{
	while (ldir)
	{
		if (ldir->d_type == 4 && ft_strncmp(ldir->dir_name, ".", 1) && ft_strncmp(ldir->dir_name, "..", 2))
		{
			if (ft_ls(append_path(ldir->path, ldir->dir_name, opt), *opt))
				*ret = 1;
		}
		ldir = ldir->next;
	}
}
