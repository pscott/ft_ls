/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:59:57 by penzo             #+#    #+#             */
/*   Updated: 2019/01/24 11:26:43 by pscott           ###   ########.fr       */
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
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <limits.h>
# include <sys/xattr.h>

# define ERROR_MEM error_memory()

typedef int			(*t_string_sort) (const char *, const char *);

typedef struct		s_lopt {
	char			*permi;
	struct passwd	*passwd;
	struct group	*group;
	unsigned int	real_size;
}					t_lopt;

typedef struct		s_maxp {
	unsigned int	nlink;
	unsigned int	owner;
	unsigned int	group;
	unsigned int	size;
	unsigned int	name;
	unsigned int	major;
	unsigned int	minor;
	unsigned int	isdevice;
	int				ino_len;
}					t_maxp;

typedef struct		s_opt {
	char			rmaj;
	char			a;
	char			l;
	char			r;
	char			t;
	char			c;
	char			o;
	char			i;
	char			u;
	char			umaj;
	char			*arg;
	int				argc;
	int				currargc;
	int				dircount;
	struct s_maxp	maxp;
	char			is_alloc;
}					t_opt;

typedef struct		s_ldir {
	char			*path;
	char			*dir_name;
	unsigned int	d_type;
	long			u;
	long			c;
	long			umaj;
	long			i;
	long			t;
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
void				parse_arg(int argc, char **argv, int *ret, t_opt *opt);

/*
 ** errors
*/

void				error_option(char c);
void				error_memory(void);
int					error_open(char *dir_name);
void				error_stat(void);
void				error_getpwuid_getgrgid(void);

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

void				print_ldir(t_ldir *ldir, t_opt *opt);
void				printf_device(t_ldir *ldir, struct stat *filestat,
		t_lopt *lopt, t_opt *opt);
void				printf_normal(t_ldir *ldir, struct stat *filestat,
		t_lopt *lopt, t_opt *opt);
/*
 ** ldir
*/

void				add_right(t_ldir *ldir, t_ldir *new_l);
void				add_left(t_ldir *ldir, t_ldir *new_l);
t_ldir				*create_ldir(const char *path, struct dirent *dirent,
		t_opt *opt);
void				add_ldir(t_ldir **ldir, t_ldir *newldir,
		int (*selected_func)(const char *, const char *));
void				add_sorted_ldir(t_ldir **ldir, t_ldir *newldir,
		int	(*selected_func)(const char *, const char *), t_opt *opt);

/*
 **	append_path
*/

char				*append_path(const char *path, const char *dir_name);

/*
 ** open_once
*/

void				open_once(int *argc, char **argv, int *ret, t_opt *opt);

/*
 ** recursion
*/

void				recursion(t_ldir *ldir, int *ret, t_opt *opt);
int					is_last(t_ldir *ldir, t_opt *opt);

/*
 **	opt_l
*/

void				print_total(t_ldir *ldir, struct stat *filestat);
void				get_max(t_ldir *ldir, struct stat *filestat, t_opt *opt);

/*
 **	time_utils
*/

char				*get_time(time_t times);

/*
 **	xattr.c
*/

char				get_attr_char(char *path);

/*
 **	link_utils
*/
char				*get_symlink(t_ldir *ldir, struct stat *filestat);

/*
 ** sorting
*/

void				sort_argv(int argc, char **argv, t_opt *opt);
t_string_sort		select_func(t_opt *opt);
void				reverse_sort_argv(int argc, char **argv, t_opt *opt);
void				sort_helper(char *s1, char *s2, t_opt *opt);

/*
 ** reverse
*/

int					reverse_ft_strcmp(const char *s1, const char *s2);

/*
**	devices_utils
*/
int					ft_major(int st_rdev);
int					ft_minor(int st_rdev);

/*
**	permissions_utils
*/
void				init_maxp(t_opt *opt);

/*
** options_adding
*/

int					add_umaj(t_opt *opt);
int					add_u(t_opt *opt);
int					add_c(t_opt *opt);

/*
** add_sorted_ldir
*/

void				add_sorted_ldir(t_ldir **ldir, t_ldir *newdir,
		t_string_sort func, t_opt *opt);
long				choose_values(t_ldir *ldir, t_ldir *newdi, t_opt *opt);
int					filetypeletter(t_ldir *ldir);
char				*get_permi(t_ldir *ldir, int stat);

/*
**	printf_select
*/
void				printf_normal_l(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt);
void				printf_device_l(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt);
void				printf_normal_o(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt);
void				printf_device_o(t_ldir *ldir, struct stat *filestat, t_lopt *lopt,
		t_opt *opt);

/*
** get_uhlen
*/

unsigned int		get_uhlen(unsigned short nb);

/*
**	failed_uid
*/

struct passwd		*my_getpwuid(struct passwd *passwd, struct stat *filestat,
		t_opt *opt);
struct group		*my_getgrgid(struct group *group, struct stat *filestat,
		t_opt *opt);

/*
** ino
*/

char				*ft_ino_itoa(ULL num);

/*
** lreg
*/

t_ldir			*create_lreg(char *path, t_opt *opt);
void			print_lreg(t_ldir *lreg);
void			free_lreg(t_ldir *lreg);
#endif
