/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_adding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:27:38 by pscott            #+#    #+#             */
/*   Updated: 2019/01/18 18:29:41 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_umaj(t_opt *opt)
{
	opt->u = 0;
	opt->c = 0;
	return (opt->umaj = 1);
}

int		add_u(t_opt *opt)
{
	opt->umaj = 0;
	opt->c = 0;
	return (opt->u = 1);
}

int		add_c(t_opt *opt)
{
	opt->u = 0;
	opt->umaj = 0;
	return (opt->c = 1);
}
