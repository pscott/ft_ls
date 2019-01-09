/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:43:06 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:45:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	malloc_opt_ldir(t_ls *ls)
{
	t_opt	*opt;
	t_ldir	*ldir;

	if (!(opt = (t_opt*)malloc(sizeof(t_opt))))
		EXIT_MEM;
	init_opt(opt);
	if (!(ldir = (t_ldir*)malloc(sizeof(t_ldir))))
		EXIT_MEM;
	ldir->path = NULL;
	ldir->next = NULL;
	ls->opt = opt;
	ls->ldir = ldir;
}

void	add_dir(char *str, t_ls *ls)
{
	(void)str;
	(void)ls;
}

void	parse_arg(int argc, char **argv, t_ls *ls)
{
	malloc_opt_ldir(ls);
	(argv)++;
	while (argc && argv && *argv && **argv == '-')
	{
		add_option(*argv, ls->opt);
		argv++;
		argc--;
	}
	while (argc)
	{
		add_dir(*argv, ls);
		argv++;
		argc--;
	}
}
