/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:36:23 by penzo             #+#    #+#             */
/*   Updated: 2019/01/24 12:35:26 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_symlink(t_ldir *ldir, struct stat *filestat)
{
	char	*res;
	char	*tmp;
	char	*path;

	if (S_ISLNK(ldir->d_type))
	{
		path = append_path(ldir->path, ldir->dir_name);
		tmp = ft_strnew(filestat->st_size);
		readlink(path, tmp, filestat->st_size);
		res = ft_strjoin(" -> ", tmp);
		if (path)
			ft_memdel((void*)&path);
		if (tmp)
			ft_memdel((void*)&tmp);
		return (res);
	}
	return ("");
}
