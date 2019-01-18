/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:40:24 by penzo             #+#    #+#             */
/*   Updated: 2019/01/18 21:23:46 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_attr_char(char *path)
{
	char	c;
	ssize_t xattr;

	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	c = '\0';
	if (xattr > 0)
		c = '@';
	else
		c = ' ';
	return (c);
}
