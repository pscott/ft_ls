/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:19:45 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 17:56:59 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		(*select_func(t_opt *opt))(const char*, const char *)
{
	if (opt->t)
	{
		if (opt->r)
			return (reverse_ft_strcmp);
		return (ft_strcmp);
	}
	if (opt->r)
		return (reverse_ft_strcmp);
	return (ft_strcmp);
}

void	sort_argv(int argc, char **argv, t_opt *opt)
{
	char	*tmp;
	int		i;
	int		j;
	int		(*selected_func)(const char *, const char *);

	if (opt->r)
		selected_func = reverse_ft_strcmp;
	else
		selected_func = ft_strcmp;
	j = 0;
	while (j < argc - 1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if ((*selected_func)(argv[i], argv[i + 1]) > 0)
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
