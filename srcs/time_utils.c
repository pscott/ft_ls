/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:52:56 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 21:21:57 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	abs_l(long a)
{
	if (!a)
		return (0);
	if (a > 0)
		return (a);
	else
		return (-a);
}

char	*get_time(time_t times)
{
	char	res[13];
	time_t	actual;
	char	*str;
	int		i;

	actual = time(0);
	if (abs_l(actual - times) > 15650000)
	{
		i = 3;
		while (++i < 11)
			res[i - 4] = ctime(&times)[i];
		res[6] = ' ';
		res[7] = ' ';
		res[8] = ctime(&times)[20];
		res[9] = ctime(&times)[21];
		res[10] = ctime(&times)[22];
		res[11] = ctime(&times)[23];
		res[12] = 0;
		str = ft_strdup(res);//TODO free
		return (str);
	}
	else
		return (ctime(&times) + 4);
}
