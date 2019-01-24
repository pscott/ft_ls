/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:52:56 by penzo             #+#    #+#             */
/*   Updated: 2019/01/24 13:20:41 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	abs_l(long a)
{
	if (!a)
		return (0);
	if (a > 0)
		return (a);
	else
		return (-a);
}

time_t	get_proper_time(struct stat *filestat, t_opt *opt)
{
	if (opt->umaj)
		return (filestat->st_birthtime);
	else if (opt->u)
		return (filestat->st_atime);
	else if (opt->c)
		return (filestat->st_ctime);
	else
		return (filestat->st_mtime);
}

char	*get_time(struct stat *filestat, t_opt *opt)
{
	char	res[13];
	time_t	actual;
	char	*str;
	time_t	times;
	int		i;

	times = get_proper_time(filestat, opt);
	actual = time(0);
	if (abs_l(actual - times) > 15650000)
	{
		i = 3;
		while (++i < 11)
			res[i - 4] = ctime(&times)[i];
		res[6] = ' ';
		res[7] = ' ';
		res[8] = ctime(&times)[20];
		res[9] = ctime(&times)[21];
		res[10] = ctime(&times)[22];
		res[11] = ctime(&times)[23];
		res[12] = 0;
		str = ft_strdup(res);
		return (str);
	}
	else
		return (ft_strdup(ctime(&times) + 4));
}
