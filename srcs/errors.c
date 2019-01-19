/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:21:20 by pscott            #+#    #+#             */
/*   Updated: 2019/01/19 13:55:17 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_option(char c)
{
	write(2, "ft_ls: illegal option -- ", 25);
	write(2, &c, 1);
	write(2, "\n", 1);
	ft_putstr_fd("usage: ft_ls [-RUacilortu] [file ...]\n", 2);
	exit(1);
}

void	error_memory(void)
{
	ft_putstr_fd("Couldn't malloc.\n", 2);
	exit(1);
}

int		error_open(char *dir_name)
{
	write(2, "ft_ls: ", 7);
	write(2, dir_name, ft_strlen(dir_name));
	write(2, ": ", 2);
	perror("");
	return (1);
}

void	error_stat(void)
{
	ft_putstr_fd("stat or lstat failed.\n", 2);
	exit(1);
}

void	error_getpwuid_getgrgid(void)
{
	ft_putstr_fd("Errr while setting user or group name\n", 2);
	exit (1);
}

