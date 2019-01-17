/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_once.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:43:19 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 16:43:38 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rearrange_argv(int i, int argc, char **argv)
{
	int j;
	j = 0;
	/*while (j < argc)
	  {
	  printf("ARGV: %s\n", argv[j]);
	  j++;
	  }*/
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argv[i] = NULL;
}

void		open_once(int *argc, char **argv, int *ret, t_opt *opt)
{
	DIR		*d;
	int		i;
	int		modif;

	modif = 0;
	sort_argv(*argc, argv, opt);
	i = 0;
	while (argv[i])
	{
		if (!(d = opendir(argv[i])))
		{
			error_open(argv[i]);
			modif++;
			rearrange_argv(i, *argc, argv);
			(*argc)--;
			*ret = 1;
		}
		else
			i++;
		if (d)
			closedir(d);
	}
}
