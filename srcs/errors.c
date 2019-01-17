/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:21:20 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 12:47:07 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_option(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	exit(1);
}

void	error_memory(void)
{
	ft_printf("Couldn't malloc.\n");
	exit(1);
}

int		error_open(char *dir_name)
{
	if (errno == 13)
		ft_printf("ls: %s: Permission denied\n", dir_name);
	else if (errno == 20 || errno == 2)
		ft_printf("ls: %s: No such file or directory\n", dir_name);
	else
	{
		ft_printf("Unknown open error at address: %p\n", dir_name);
	}
	return (1);
}
