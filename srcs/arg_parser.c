/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:43:06 by pscott            #+#    #+#             */
/*   Updated: 2019/01/12 14:02:53 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt *malloc_opt(void)
{
	t_opt	*res;

	if (!(res = (t_opt*)malloc(sizeof(t_opt))))
		EXIT_MEM;
	init_opt(res);
	return (res);
}

void	parse_arg(int argc, char **argv, t_opt *opt)
{
	(argv)++;
	while (argc && argv && *argv && **argv == '-')
	{
		add_option(*argv, opt);
		argv++;
		argc--;
	}
	while (argc)
	{
		opt->arg = *argv;
		ft_ls(*argv, opt);
		argv++;
		argc--;
	}
}
