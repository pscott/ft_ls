/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_once.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:43:19 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 14:46:38 by pscott           ###   ########.fr       */
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

void	sort_argv(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (j < argc - 1)
	{
		i = 0;
		while (i < argc- 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void		open_once(int *argc, char **argv, int *ret)
{
	DIR		*d;
	int		i;
	int		modif;

	modif = 0;
	sort_argv(*argc, argv);
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
