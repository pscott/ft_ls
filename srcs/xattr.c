/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:40:24 by penzo             #+#    #+#             */
/*   Updated: 2019/01/15 17:57:11 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_attr_char(char *path)
{
	char	c;
	ssize_t xattr;

	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	//if (xattr < 0)
	//	xattr = 0;
	c = '\0';
	if (xattr > 0)
		c = '@';
	//else if (acl != NULL)
	//	c = '+';
	else
		c = ' ';
	return(c);
}
