/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_once.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:43:19 by pscott            #+#    #+#             */
/*   Updated: 2019/01/19 16:44:42 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		rearrange_argv(int i, int argc, char **argv)
{
	int	j;

	j = 0;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argv[i] = NULL;
}

static void		print_spec_l(char *path, struct stat *filestat, t_opt *opt)
{
	
}

static int		is_not_dir(char *path, int argc, t_opt *opt)
{
	struct stat filestat;

	(void)opt;
	//	TODO: if ends with "/";
	if (stat(path, &filestat) == -1)
	{
		error_open(path);
		return (1);
	}
	if (S_ISDIR(filestat.st_mode))
		return (0);
	if (opt->l)
		print_spec_l(path, &filestat, opt);
		ft_printf("%s\n", path);
	if (argc > 1)
		write(1, "\n", 1);
	return (1);
}

void		open_once(int *argc, char **argv, int *ret, t_opt *opt)
{
	int		i;
	int		modif;
	char	tmp[PATH_MAX];

	modif = 0;
	sort_argv(*argc, argv, opt);
	i = 0;
	while (argv[i])
	{
		if (is_not_dir(argv[i], *argc, opt))
		{
			modif++;
			rearrange_argv(i, *argc, argv);
			(*argc)--;
			*ret = 1;
		}
		else
		{
			if (argv[i][ft_strlen(argv[i] - 1)] == '/')
			{
				if (readlink(argv[i], tmp,ft_strlen(argv[i])) != -1)
					argv[i] = tmp;
			}
			i++;
		}
	}
}
