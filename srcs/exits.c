/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:21:20 by pscott            #+#    #+#             */
/*   Updated: 2019/01/12 12:55:53 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_option(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	exit(1);
}

void	exit_memory(void)
{
	ft_printf("Couldn't malloc.\n");
	exit(1);
}

void	exit_open(char *dir_name)
{
	printf("ls: %s: No such file or directory\n", dir_name);
	exit(1);
}
