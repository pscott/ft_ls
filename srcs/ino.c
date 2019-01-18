/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ino.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 22:23:51 by pscott            #+#    #+#             */
/*   Updated: 2019/01/18 22:50:13 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_ino_itoa(ULL n)
{
	int		len;
	char	*res;

	len = get_llen(n);
	if (!(res = ft_strnew(len + 1)))
		ERROR_MEM;
	res[len] = ' ';
	while (n > 9)
	{
		res[len - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	res[0] = n + '0';
	return (res);
}
