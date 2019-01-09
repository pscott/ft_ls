/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:07:13 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:45:55 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_opt(t_opt *opt)
{
	opt->rmaj = 0;
	opt->a = 0;
	opt->l = 0;
	opt->r = 0;
	opt->t = 0;
}

int		add_valid_option(char c, t_opt *opt)
{
	if (c == 'R')
		return (opt->rmaj = 1);
	else if (c == 'a')
		return (opt->a = 1);
	else if (c == 'l')
		return (opt->l = 1);
	else if (c == 'r')
		return (opt->r = 1);
	else if (c == 't')
		return (opt->t = 1);
	return (0);
}

void	add_option(char *str, t_opt *opt)
{
	// tester avec str == NULL ?

	str++;
	while (*str)
	{
		if (!add_valid_option(*str, opt))
			exit_option(*str);
		str++;
	}
}
