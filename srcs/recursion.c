/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:44:10 by pscott            #+#    #+#             */
/*   Updated: 2019/01/16 21:55:54 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_last(t_ldir *ldir, t_opt *opt)
{
	if (opt->dircount == 0)
	{
		if (!ldir || !ldir->next)
		{
			return (1);
		}
	}
	return (0);
}

void	recursion(t_ldir *ldir, int *ret, t_opt *opt)
{
	char	*newpath;

	if (!is_last(ldir, opt))
		write(1, "\n", 1);
	while (ldir)
	{
		if (ldir->d_type == 4 && ft_strncmp(ldir->dir_name, ".", 1)
				&& ft_strncmp(ldir->dir_name, "..", 2))
		{
			if (!(newpath = append_path(ldir->path, ldir->dir_name, opt)))
				return (error_memory());
			if (opt->argc < 2)
			{
				ft_printf("%s:\n", newpath);
			}
			if (ldir->d_type == 4)
			{
				opt->dircount--;
			}
			if (ft_ls(newpath, *opt))
				*ret = 1;
			free(newpath);
		}
		ldir = ldir->next;
	}
}
