/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:10:16 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 18:16:09 by pscott           ###   ########.fr       */
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

void	reset_opt(int argc, char **argv, t_opt *opt)
{
	opt->arg = *argv;
	opt->currargc = argc;
	opt->dircount = 0;
}

void	parse_arg(int argc, char **argv, int *ret, t_opt *opt)
{
	while (argc && argv && *argv && **argv == '-')
	{
		add_option(*argv, opt);
		argv++;
		argc--;
	}
	open_once(&argc, argv, ret, opt);
	opt->argc = argc;
	if (!(*argv))
	{
		reset_opt(argc, argv, opt);
		if (ft_ls(".", *opt))
			*ret = 1;
	}
	while (argc > 0)
	{
		reset_opt(argc, argv, opt);
		if (ft_ls(*argv, *opt))
			*ret = 1;
		argv++;
		argc--;
		if (argc > 0 && !opt->rmaj)
			write(1, "\n", 1);
	}
}
