/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_once.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:43:19 by pscott            #+#    #+#             */
/*   Updated: 2019/01/14 19:23:42 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			open_once(int argc, char **argv)
{
	DIR		*d;
	int		i;
	int		modif;

	i = 0;
	modif = 0;
	while (i < argc)
	{
		if (!(d = opendir(argv[i])))
		{
			error_open(argv[i]);
			modif++;
		}
		if (d)
			closedir(d);
		i++;
	}
	return (modif);
}
