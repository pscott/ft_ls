/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devices_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:22:10 by penzo             #+#    #+#             */
/*   Updated: 2019/01/17 17:25:48 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_major(int st_rdev)
{
	int		res;

	res = (st_rdev >> 24) & 0xff;
	return (res);
}

int		ft_minor(int st_rdev)
{
	int		res;

	res = st_rdev & 0xffffff;
	return (res);
}

