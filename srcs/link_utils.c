/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:36:23 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 21:33:11 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_symlink(t_ldir *ldir, struct stat *filestat)
{
	char	*res;
	char	*path;

	if (ldir->d_type == 10)
	{
		path = append_path(ldir->path, ldir->dir_name);
		res = ft_strnew(filestat->st_size + 1);
		readlink(path, res, ft_strlen(path));
		res = ft_strjoin(" -> ", res);
		if (path)
			free(path);
		return (res);
	}
	return ("");
}
