/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:43:06 by pscott            #+#    #+#             */
/*   Updated: 2019/01/08 20:10:28 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_arg(char **argv, t_ls *ls)
{
	while (*argv && **argv = '-')
	{
		add_option(*argv, ls->opt);
		(*argv)++;
	}
	while (*argv)
	{
		add_dir(*argv, ls);
		(*argv)++;
	}
}
