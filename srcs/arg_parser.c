/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:43:06 by pscott            #+#    #+#             */
/*   Updated: 2019/01/16 21:55:55 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	*malloc_opt(void)
{
	t_opt	*res;

	if (!(res = (t_opt*)malloc(sizeof(t_opt))))
		ERROR_MEM;
	init_opt(res);
	return (res);
}

int		parse_arg(int argc, char **argv, t_opt *opt)
{
	int ret;
	int modif;

	ret = 0;
	(argv)++;
	while (argc && argv && *argv && **argv == '-')
	{
		add_option(*argv, opt);
		argv++;
		argc--;
	}
	//TODO:sort_argv(argc, argv);
	modif = open_once(argc, argv);
	argc = argc - modif;
	opt->argc = argc;
	while (argc > 0)
	{
		opt->arg = *argv;
		opt->currargc = argc;
		opt->dircount = 0;
		if (ft_ls(*argv, *opt))
			ret = 1;
		argv++;
		argc--;
		if (argc > 0 && !opt->rmaj)
			write(1, "\n", 1);
	}
	return (ret);
}
