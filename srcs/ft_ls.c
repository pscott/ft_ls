/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:50:40 by penzo             #+#    #+#             */
/*   Updated: 2019/01/14 19:21:38 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(const char *path, t_opt opt)
{
	struct dirent	*dirent;
	DIR				*directory;
	t_ldir			*ldir;
	int				ret;

	ldir = NULL;
	ret = 0;
	if (!(directory = opendir(path)))
		return (1);
	if (ft_strncmp(path, ".", 1))
		ft_printf("%s:\n", path);
	while ((dirent = readdir(directory)))
	{
		if (!ldir)
			ldir = create_ldir(path, dirent, &opt);
		else
			add_ldir(&ldir, create_ldir(path, dirent, &opt), &opt);
	}
	if (ldir)
	{
		while(ldir->prev)//TODO: fix this pls (ldir->prev)
			ldir = ldir->prev;
		print_ldir(ldir, &opt);
		if (opt.rmaj)
		{
			while (ldir)
			{
				if (ldir->d_type == 4 && ft_strncmp(ldir->dir_name, ".", 1)
						&& ft_strncmp(ldir->dir_name, "..", 2)) //TODO: not worth checking strcmps twice (once in create ldir, second time here)
				if (ft_ls(append_path(ldir->path, ldir->dir_name, &opt), opt))
					ret = 1;
				ldir = ldir->next;
			}
		}
		ft_memdel((void*)&ldir);
	}
	(void)closedir(directory);
	return (ret);}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	int		ret;

	if (argv)
		(*argv)++;
	opt = malloc_opt();
	ret = parse_arg(argc - 1, argv, opt);
	ft_memdel((void*)&opt);
	return (ret);
}
