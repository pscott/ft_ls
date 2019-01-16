/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:36:23 by penzo             #+#    #+#             */
/*   Updated: 2019/01/16 16:09:55 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_symlink(t_ldir *ldir, struct stat *filestat, t_opt *opt)
{
	char	*res;

	//res = NULL;
	if (ldir->d_type == 10)
	{
		res = ft_strnew(filestat->st_size + 1);
		readlink(append_path(ldir->path, ldir->dir_name, opt), res, filestat->st_size + 1);
		res = ft_strjoin(" -> ", res);
		return (res);
	}
	return("");
}
