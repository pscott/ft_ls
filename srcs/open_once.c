/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_once.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:43:19 by pscott            #+#    #+#             */
/*   Updated: 2019/01/24 13:40:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		rearrange_argv(int i, int argc, char **argv)
{
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

static int		get_type(char *path, int *ret, t_opt *opt)
{
	struct stat filestat;

	(void)opt;
	if (lstat(path, &filestat) == -1)
	{
		error_open(path);
		*ret = 1;
		return (1);
	}
	if (S_ISLNK(filestat.st_mode))
	{
		if (path[ft_strlen(path) - 1] == '/')
			return (0);
		return (2);
	}
	else if (S_ISDIR(filestat.st_mode))
		return (0);
	return (2);
}

void			pop_argv(int *i, int *argc, char **argv)
{
	rearrange_argv(*i, *argc, argv);
	(*argc)--;
	(*i)--;
}

void			print_argv(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	ft_printf("\n\n");
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
		if (get_type(argv[i], ret, opt) == 1)
			pop_argv(&i, argc, argv);
		else if (get_type(argv[i], ret, opt) == 2)
		{
			if (!lreg)
				lreg = create_lreg(argv[i], opt);
			else
				add_right_and_move(&lreg, create_lreg(argv[i], opt));
			pop_argv(&i, argc, argv);
		}
		else if (argv[i][ft_strlen(argv[i] - 1)] == '/'
				&& readlink(argv[i], tmp, ft_strlen(argv[i])) != -1)
			argv[i] = tmp;
	}
	print_lreg(lreg, *argc, opt);
	free_lreg(lreg);
}
