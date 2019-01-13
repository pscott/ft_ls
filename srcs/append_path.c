/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:24:01 by penzo             #+#    #+#             */
/*   Updated: 2019/01/13 13:42:20 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*append_path(const char *path, const char *dir_name, t_opt *opt)
{
	int		len;
	char	*res;
	int		pathlen;
	int		dirlen;

	pathlen = ft_strlen(path);
	dirlen = ft_strlen(dir_name);
	len = pathlen + dirlen + 1;
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(res, path, pathlen);
	res[pathlen] = '/';
	ft_strncpy((res + pathlen + 1), dir_name, dirlen);
	(void)opt;//TODO
	return (res);
}
