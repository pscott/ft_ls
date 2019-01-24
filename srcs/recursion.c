/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:44:10 by pscott            #+#    #+#             */
/*   Updated: 2019/01/24 16:19:54 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_last(t_ldir *ldir, t_opt *opt)
{
	if (opt->dircount <= 0)
	{
		if (opt->currargc < 2)
		{
			if (!ldir)
				return (1);
			if (!ldir->next)
				return (1);
			if (ft_strcmp(ldir->dir_name, ".") == 0)
				return (1);
			if (ft_strcmp(ldir->dir_name, "..") == 0)
				return (1);
		}
		if ((!ldir && opt->currargc < 2) || (!ldir->next && opt->currargc < 2))
			return (1);
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
		if ((S_ISDIR(ldir->d_type) || ldir->d_type == 0)
		&& ft_strcmp(ldir->dir_name, ".") && ft_strcmp(ldir->dir_name, ".."))
		{
			if (!(newpath = append_path(ldir->path, ldir->dir_name)))
				return (error_memory());
			if (opt->argc < 2)
				ft_printf("%s:\n", newpath);
			opt->dircount--;
			if (ft_ls(newpath, *opt))
				*ret = 1;
			free(newpath);
		}
		ldir = ldir->next;
	}
}
