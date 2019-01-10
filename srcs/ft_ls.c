/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:51:45 by pscott            #+#    #+#             */
/*   Updated: 2019/01/10 16:07:15 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(const char *path, t_opt *opt)
{
	struct dirent	*dirent;
	DIR				*directory;
	t_ldir			*ldir;

	if(!(directory = opendir(path)))//TODO: protect
		//error
	while (dirent = readdir)
	{
		add_ldir(ldir, dirent, path, opt);
	}
	print_ldir(ldir, opt);
	while (ldir)
	{
		if (ldir->d_type == 8)
		{
			printf("%s:\n", ldir->dirname);
			ft_ls(ldir->path, opt);
		}
		ldir = ldir->next;
	}
	//free list
	return;//TODO: return value
}

int	main(int argc, char **argv)
{
	t_opt *opt;

	//	malloc everything ?
	if (argv)
		(*argv)++;
	opt = malloc_opt();
	parse_arg(argc, argv, opt);
	print_opt(opt);
	ft_memdel((void*)&opt);
	return (0);
}
