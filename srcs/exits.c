/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:21:20 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:15:29 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_option(char c)
{
	printf("ls: illegal option -- %c\n", c);
	printf("usage: ls [-Ralrt] [file ...]\n");
	exit(1);
}

void	exit_memory(void)
{
	printf("Couldn't malloc.\n");
	exit(1);
}
