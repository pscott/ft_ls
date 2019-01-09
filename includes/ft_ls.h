/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:52:09 by pscott            #+#    #+#             */
/*   Updated: 2019/01/09 13:45:57 by pscott           ###   ########.fr       */
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
	struct s_ldir	*next;
}					t_ldir;

typedef struct		s_ls {
	t_opt			*opt;
	t_ldir			*ldir;
}					t_ls;

/*
 * arg_parser 
*/

void				parse_arg(int argc, char **argv, t_ls *ls);

/* 
 * exits
*/

void				exit_option(char c);
void				exit_memory(void);

/*
 * options
*/

int					add_valid_option(char c, t_opt *opt);
void				add_option(char *str, t_opt *opt);
void				init_opt(t_opt *opt);

/*
 * free
*/

int					free_everything(t_ls *ls);

/*
 * print_helpers
*/

void				print_opt(t_opt *opt);
void				print_ldir(t_ldir *ldir);
#endif
