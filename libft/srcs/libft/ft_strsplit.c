/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:10:44 by pscott            #+#    #+#             */
/*   Updated: 2018/11/11 13:30:38 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	how_many(char const *s, char c)
{
	size_t	i;
	size_t	nb;
	int		on_word;

	i = 0;
	nb = 0;
	on_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			on_word = 0;
		else
		{
			if (!(on_word))
			{
				on_word = 1;
				nb++;
			}
		}
		i++;
	}
	return (nb);
}

static	size_t	how_long(char const *s, char c, size_t *j)
{
	size_t	nb;

	nb = 0;
	while (s[*j + nb] && s[*j + nb] != c)
		nb++;
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s || !(tab = (char **)malloc(sizeof(*tab) * (how_many(s, c) + 1))))
		return (NULL);
	while (s[j])
	{
		k = 0;
		if (!(how_long(s, c, &j)))
			j++;
		else if (!(tab[i] = ft_strnew(how_long(s, c, &j))))
			return (NULL);
		else
		{
			ft_strncpy(tab[i], &s[j], how_long(s, c, &j));
			j = j + how_long(s, c, &j);
			i++;
		}
	}
	tab[how_many(s, c)] = 0;
	return (tab);
}
