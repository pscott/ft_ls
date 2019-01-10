/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:44:36 by pscott            #+#    #+#             */
/*   Updated: 2018/11/15 17:05:39 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *res;

	if (!(res = ft_strnew(ft_strlen(s1))))
		return (NULL);
	return (ft_strcpy(res, s1));
}
