/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:50:40 by penzo             #+#    #+#             */
/*   Updated: 2019/01/16 21:53:11 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir	*create_list(DIR *directory, char *path, t_opt *opt)
{
	struct dirent	*dirent;
	t_ldir			*ldir;

	ldir = NULL;
	while ((dirent = readdir(directory)))
	{
		if (!ldir)
			ldir = create_ldir(path, dirent, opt);
		else
			add_ldir(&ldir, create_ldir(path, dirent, opt), opt);
	}
	while (ldir && ldir->prev)
		ldir = ldir->prev;
	return (ldir);
}

int		ft_ls(const char *path, t_opt opt)
{
	DIR				*directory;
	t_ldir			*ldir;
	int				ret;

	ret = 0;
	if (!(directory = opendir(path)))
		return (1);
	ldir = create_list(directory, (char*)path, &opt);
	if (opt.argc > 1)
		ft_printf("%s:\n", path);
	print_ldir(ldir, &opt);
	if (opt.currargc > 1)
		write(1, "\n", 1);
	if (opt.rmaj)
		recursion(ldir, &ret, &opt);
	ft_memdel((void*)&ldir);
	(void)closedir(directory);
	return (ret);
}

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
