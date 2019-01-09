/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:52:09 by pscott            #+#    #+#             */
/*   Updated: 2019/01/08 20:10:29 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>

// please check that those libs are allowed 
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_opt {
	char		l;
	char		rmaj;
	char		a;
	char		r;
	char		t;
}				t_opt;

typedef struct	s_ldir {
	char		*path;
	t_ldir		*next;
}				t_ldir;

typedef struct	s_ls {
	t_opt	*opt;
	t_ldir	*ldir;
}				t_ls;

void			parse_arg(char **argv, t_opt *opt);
#endif
