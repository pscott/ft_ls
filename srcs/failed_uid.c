/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_uid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:05:37 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 23:50:25 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct passwd	*my_getpwuid(struct passwd *passwd, struct stat *filestat,
		t_opt *opt)
{
	struct passwd	*backup_passwd;

	opt->is_alloc = 0;
	if (!(passwd = getpwuid(filestat->st_uid)))
	{
		if (errno)
			error_getpwuid_getgrgid();
		else
		{
			if (!(backup_passwd = (struct passwd*)malloc(sizeof(struct passwd))))
				error_memory();
			backup_passwd->pw_name = ft_itoa(filestat->st_uid);
			opt->is_alloc = 1;
			return (backup_passwd);
		}
	}
	return (passwd);
}

struct group	*my_getgrgid(struct group *group, struct stat *filestat,
		t_opt *opt)
{
	struct group	*backup_group;

	opt->is_alloc = 0;
	if (!(group = getgrgid(filestat->st_gid)))
	{
		if (errno)
			error_getpwuid_getgrgid();
		else
		{
			if (!(backup_group = (struct group*)malloc(sizeof(struct group))))
				error_memory();
			backup_group->gr_name = ft_itoa(filestat->st_gid);
			opt->is_alloc = 1;
			return (backup_group);
		}
	}
	return (group);
}
