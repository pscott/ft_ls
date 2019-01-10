/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:24:01 by penzo             #+#    #+#             */
/*   Updated: 2019/01/10 19:03:13 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*append_path(const char *path, const char *dir_name, t_opt *opt)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	len = ft_strlen(path) + ft_strlen(dir_name) + 1;
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(res, path, len);
	res[ft_strlen(path)] = '/';
	i = ft_strlen(path) + 1;
	j = 0;
	while (i < len)
	{
		res[i] = dir_name[j];
		i++;
		j++;
	}
	res[i] = 0;
	(void)opt;//TODO
	return (res);
}
