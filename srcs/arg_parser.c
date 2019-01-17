/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:10:16 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 20:20:21 by pscott           ###   ########.fr       */
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
	if (!(opt->argc = argc))
	{
		reset_opt(argc, argv, opt);
		if (ft_ls(".", *opt))
			*ret = 1;
		return ;
	}
	open_once(&argc, argv, ret, opt);
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
