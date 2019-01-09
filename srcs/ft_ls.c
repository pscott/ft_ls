/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:51:45 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:07:51 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	*ls;

	if (!(ls = (t_ls*)malloc(sizeof(t_ls))))
		EXIT_MEM;
//	malloc everything ?
	(void)argc;
	if (argv)
		(*argv)++;
	parse_arg(argc, argv, ls);
	print_opt(ls->opt);
	print_ldir(ls->ldir);
	return (free_everything(ls));
}
