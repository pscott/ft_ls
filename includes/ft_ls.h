/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:52:09 by pscott            #+#    #+#             */
/*   Updated: 2019/01/11 14:42:54 by penzo            ###   ########.fr       */
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
# include "libft.h"
# include <stdio.h>

# define EXIT_MEM exit_memory()

typedef struct		s_opt {
	char			rmaj;
	char			a;
	char			l;
	char			r;
	char			t;
}					t_opt;

typedef struct		s_ldir {
	char			*path;
	char			*dir_name;
	char			d_type;
	struct s_ldir	*prev;
	struct s_ldir	*next;
}					t_ldir;

/*
 * ft_ls
*/

void				ft_ls(const char *path, t_opt *opt);

/*
 * arg_parser 
*/

t_opt				*malloc_opt(void);
void				parse_arg(int argc, char **argv, t_opt *opt);

/* 
 * exits
*/

void				exit_option(char c);
void				exit_memory(void);
void				exit_open(void);

/*
 * options
*/

int					add_valid_option(char c, t_opt *opt);
void				add_option(char *str, t_opt *opt);
void				init_opt(t_opt *opt);
void				opt_l(t_ldir *ldir, t_opt *opt);

/*
 * free
*/

void				free_ldir(t_ldir *ldir);

/*
 * print_helpers
*/

void				print_opt(t_opt *opt);
void				print_ldir(t_ldir *ldir, t_opt *opt);

/*
 * ldir
*/

void				add_right(t_ldir *ldir, t_ldir *new_l);
void				add_right(t_ldir *ldir, t_ldir *new_l);
t_ldir				*create_ldir(const char *path, struct dirent *dirent, t_opt *opt);
void				add_ldir(t_ldir **ldir, t_ldir *newldir, t_opt *opt);

/*
**	append_path
*/

char				*append_path(const char *path, const char *dir_name, t_opt *opt);

#endif
