/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:19:35 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 13:24:17 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_maxp(t_opt *opt)
{
	opt->maxp.nlink = 1;
	opt->maxp.owner = 0;
	opt->maxp.group = 5;
	opt->maxp.size = 0;
	opt->maxp.major = 0;
	opt->maxp.minor = 0;
	opt->maxp.isdevice = 0;
}
