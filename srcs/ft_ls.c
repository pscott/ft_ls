/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:50:40 by penzo             #+#    #+#             */
/*   Updated: 2019/01/17 18:56:52 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir	*create_list(DIR *directory, char *path, t_opt *opt)
{
	struct dirent	*dirent;
	t_string_sort	selected_func;
	t_ldir			*ldir;

	ldir = NULL;
	selected_func = select_func(opt);
	while ((dirent = readdir(directory)))
	{
		if (!ldir)
			ldir = create_ldir(path, dirent, opt);
		else
			add_ldir(&ldir, create_ldir(path, dirent, opt), selected_func);
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
	if (opt.currargc > 1 && opt.rmaj)
		write(1, "\n", 1);
	if (opt.rmaj)
		recursion(ldir, &ret, &opt);
	free_ldir(ldir);
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
	(argv)++;
	parse_arg(argc - 1, argv, &ret, opt);
	ft_memdel((void*)&opt);
	return (ret);
}
