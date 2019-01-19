/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_once.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:43:19 by pscott            #+#    #+#             */
/*   Updated: 2019/01/19 19:33:52 by pscott           ###   ########.fr       */
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

/*
** Returns 1 if it cannot open.
** Returns 0 if it is a DIR or if it is a symlink ending with /
** Returns 2 if it is not a DIR (i.e. regular file or symlink not ending with /
*/

static int		is_not_dir(char *path, t_opt *opt)
{
	struct stat filestat;

	(void)opt;
	if (stat(path, &filestat) == -1)
	{
		error_open(path);
		return (1);
	}
	if (S_ISDIR(filestat.st_mode))
		return (0);
	if (S_ISLNK(filestat.st_mode) && path[ft_strlen(path) - 1] == '/')
		return (0);
	return (2);
}

void			pop_argv(int *i, int *ret, int *argc, char **argv)
{
	rearrange_argv(*i, *argc, argv);
	(*argc)--;
	(*i)--;
	*ret = 1;
}

void			open_once(int *argc, char **argv, int *ret, t_opt *opt)
{
	int				i;
	char			tmp[PATH_MAX];
	t_ldir			*lreg;

	i = -1;
	lreg = NULL;
	while (argv[++i])
	{
		if (is_not_dir(argv[i], opt) == 1)
			pop_argv(&i, ret, argc, argv);
		if (is_not_dir(argv[i], opt) == 2)
		{
			if (!lreg)
				lreg = create_lreg(argv[i], opt);
			else
				add_right(lreg, create_lreg(argv[i], opt));
			pop_argv(&i, ret, argc, argv);
		}
		else if (argv[i][ft_strlen(argv[i] - 1)] == '/'
				&& readlink(argv[i], tmp, ft_strlen(argv[i])) != -1)
			argv[i] = tmp;
	}
	print_lreg(lreg);
	free_lreg(lreg);
}
