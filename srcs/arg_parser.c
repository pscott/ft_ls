/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:43:06 by pscott            #+#    #+#             */
/*   Updated: 2019/01/16 14:23:28 by pscott           ###   ########.fr       */
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
	modif = open_once(argc, argv);
	opt->argc = argc;
	while (argc)
	{
		opt->arg = *argv;
		if (ft_ls(*argv, *opt))
			ret = 1;
		argv++;
		argc--;
		if (argc - modif > 0)
			write(1, "\n", 1);
	}
	return (ret);
}
