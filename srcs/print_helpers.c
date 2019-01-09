/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:59:55 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:43:29 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_opt(t_opt *opt)
{
	printf("\n\t\tOPT\n");
	printf("R: %d\t", opt->rmaj);
	printf("a: %d\t", opt->a);
	printf("l: %d\t", opt->l);
	printf("r: %d\t", opt->r);
	printf("t: %d\n", opt->t);
}

void	print_ldir(t_ldir *ldir)
{
	printf("\n\t\tLDIR\n");
	while (ldir)
	{
		printf("PATH: %s\tNEXT: %p\n", ldir->path, ldir->next);
		ldir = ldir->next;
	}
}
