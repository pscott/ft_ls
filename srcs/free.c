/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:47:32 by pscott            #+#    #+#             */
/*   Updated: 2019/01/10 18:30:58 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_ldir(t_ldir *ldir)
{
	t_ldir *tmp;

	while (ldir)
	{
		tmp = ldir;
		ft_memdel((void*)&(ldir->path));
		ldir = ldir->next;
		ft_memdel((void*)&tmp);
	}
}
