/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:51:45 by pscott            #+#    #+#             */
/*   Updated: 2019/01/08 20:10:37 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	*ls;
	t_opt	*opt;
	t_ldir	*ldir;

//	malloc everything ?
	(void)argc;
	if (argv)
		(*argv)++;
	parse_arg(argv, &ls);
	return (0);
}
