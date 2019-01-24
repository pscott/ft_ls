/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:36:23 by penzo             #+#    #+#             */
/*   Updated: 2019/01/24 16:00:25 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_symlink(t_ldir *ldir)
{
	char	*res;
	char	tmp[PATH_MAX];
	char	*path;

	if (S_ISLNK(ldir->d_type))
	{
		path = append_path(ldir->path, ldir->dir_name);
		tmp[readlink(path, tmp, PATH_MAX)] = 0;
		res = ft_strjoin(" -> ", tmp);
		if (path)
			ft_memdel((void*)&path);
		return (res);
	}
	return ("");
}
