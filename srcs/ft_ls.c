/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:50:40 by penzo             #+#    #+#             */
/*   Updated: 2019/01/12 14:24:43 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(const char *path, t_opt *opt)
{
	struct dirent	*dirent;
	DIR				*directory;
	t_ldir			*ldir;

	ldir = NULL;
	if(!(directory = opendir(path)))
		exit_open((char*)path);//TODO: CHECK IF MSG IS CORRECT
	while ((dirent = readdir(directory)))
	{
		if (!ldir)
			ldir = create_ldir(path, dirent, opt);
		else
			add_ldir(&ldir, create_ldir(path, dirent, opt), opt);
	}
	if (ldir)
	{
		while(ldir->prev)
			ldir = ldir->prev;
		print_ldir(ldir, opt);
		if (opt->rmaj)
		{
			while (ldir)
			{
				if (ldir->d_type == 4 && ft_strcmp(ldir->dir_name, ".")
						&& ft_strcmp(ldir->dir_name, "..")) //TODO: not worth checking strcmps twice (once in create ldir, second time here)
				ft_ls(append_path(ldir->path, ldir->dir_name, opt), opt);
				ldir = ldir->next;
			}
		}
		ft_memdel((void*)&ldir);
	}
	return;//TODO: return value
}

int	main(int argc, char **argv)
{
	t_opt *opt;

	//	malloc everything ?
	if (argv)
		(*argv)++;
	opt = malloc_opt();
	parse_arg(argc - 1, argv, opt);
//	print_opt(opt);
	ft_memdel((void*)&opt);
	return (0);
}
