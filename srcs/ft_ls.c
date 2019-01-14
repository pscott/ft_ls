/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:50:40 by penzo             #+#    #+#             */
/*   Updated: 2019/01/13 16:56:36 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(const char *path, t_opt *opt)
{
	struct dirent	*dirent;
	DIR				*directory;
	t_ldir			*ldir;
	int				ret;

	ldir = NULL;
	ret = 0;
	if(ft_strcmp(path, opt->arg))
		ft_printf("%s:\n", path);
	if(!(directory = opendir(path)))
		return (exit_open((char*)path));//TODO: CHECK IF MSG IS CORRECT
	while ((dirent = readdir(directory)))
	{
		if (!ldir)
			ldir = create_ldir(path, dirent, opt);
		else
			add_ldir(&ldir, create_ldir(path, dirent, opt), opt);
	}
	if (ldir)
	{
		while(ldir->prev)//TODO: fix this pls
			ldir = ldir->prev;
		if (!(opt->l))
			print_ldir(ldir, opt);
		else
		{
			print_opt(opt);//benz
			opt_l(ldir, opt);//benz
		}
		if (opt->rmaj)
		{
			while (ldir)
			{
				if (ldir->d_type == 4 && ft_strncmp(ldir->dir_name, ".", 1)
						&& ft_strncmp(ldir->dir_name, "..", 2)) //TODO: not worth checking strcmps twice (once in create ldir, second time here)
				if (ft_ls(append_path(ldir->path, ldir->dir_name, opt), opt))
					ret = 1;
				ldir = ldir->next;
			}
		}
		ft_memdel((void*)&ldir);
	}
	return (ret);//TODO: return value
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	int		ret;

	//	malloc everything ?
	if (argv)
		(*argv)++;
	opt = malloc_opt();
	ret = parse_arg(argc - 1, argv, opt);
//	print_opt(opt);
	ft_memdel((void*)&opt);
	return (ret);
}
