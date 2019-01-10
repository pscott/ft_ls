/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:43:06 by pscott            #+#    #+#             */
/*   Updated: 2019/01/10 15:20:05 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt *malloc_opt(void)
{
	t_opt	*res;

	if (!(res= (t_opt*)malloc(sizeof(t_opt))))
		EXIT_MEM;
	init_opt(res);
	return (res);
}

void	ft_ls(char *str, t_opt *opt)
{
	(void)str;
	(void)opt;
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
		ft_ls(*argv, opt);
		argv++;
		argc--;
	}
}
