/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:51:07 by penzo             #+#    #+#             */
/*   Updated: 2019/01/16 19:41:26 by penzo            ###   ########.fr       */
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
# include <uuid/uuid.h>//ben
# include <pwd.h>//ben
# include <grp.h>//ben
# include <time.h>//ben
# include <sys/xattr.h>//ben

# define ERROR_MEM error_memory()

typedef struct		s_maxp {
	unsigned int	nlink;
	unsigned int	owner;
	unsigned int	group;
	unsigned int	size;
	unsigned int	name;
}					t_maxp;

typedef struct		s_opt {
	char			rmaj;
	char			a;
	char			l;
	char			r;
	char			t;
	char			*arg;
	int				argc;
	struct s_maxp	maxp;
}					t_opt;

typedef struct		s_ldir {
	char			*path;
	char			*dir_name;
	char			d_type;
	struct s_ldir	*prev;
	struct s_ldir	*next;
}					t_ldir;

/*
 ** ft_ls
*/

int					ft_ls(const char *path, t_opt opt);

/*
** arg_parser
*/

t_opt				*malloc_opt(void);
int					parse_arg(int argc, char **argv, t_opt *opt);

/*
 ** errors
*/

void				error_option(char c);
void				error_memory(void);
int					error_open(char *dir_name);

/*
 ** options
*/

int					add_valid_option(char c, t_opt *opt);
void				add_option(char *str, t_opt *opt);
void				init_opt(t_opt *opt);
void				opt_l(t_ldir *ldir, struct stat *filestat, t_opt *opt);

/*
 ** free
*/

void				free_ldir(t_ldir *ldir);

/*
 ** print_helpers
*/

void				print_opt(t_opt *opt);
void				print_ldir(t_ldir *ldir, t_opt *opt);

/*
 ** ldir
*/

void				add_right(t_ldir *ldir, t_ldir *new_l);
void				add_right(t_ldir *ldir, t_ldir *new_l);
t_ldir				*create_ldir(const char *path, struct dirent *dirent,
		t_opt *opt);
void				add_ldir(t_ldir **ldir, t_ldir *newldir, t_opt *opt);

/*
 **	append_path
*/

char				*append_path(const char *path, const char *dir_name,
		t_opt *opt);

/*
 ** open_once
*/

int					open_once(int argc, char **argv);

/*
 ** recursion
*/

void			recursion(t_ldir *ldir, int *ret, t_opt *opt);

/*
 *	opt_l
*/

void				print_total(t_ldir *ldir, struct stat *filestat,
		t_opt *opt);
void				get_max(t_ldir *ldir, struct stat *filestat, t_opt *opt);

/*
 *	time_utils.c
*/

char				*get_time(time_t times);

/*
 *	xattr.c
*/

char				get_attr_char(char *path);

/*
 *	link_utils.c
*/
char				*get_symlink(t_ldir *ldir, struct stat *filestat,
		t_opt *opt);
#endif
