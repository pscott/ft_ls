// header

#include "ft_ls.h"

int		get_max_ino(t_ldir *ldir)
{
	int max;
	int	this_len;

	max = 0;
	while (ldir)
	{
		this_len = get_llen(ldir->i);
		if (this_len > max)
			max = this_len;
		ldir = ldir->next;
	}
	return (max);
}

int		get_max_len(t_ldir *ldir)
{
	int max;
	int	this_len;

	max = 0;
	while (ldir)
	{
		this_len = ft_strlen(ldir->dir_name);
		if (this_len > max)
			max = this_len;
		ldir = ldir->next;
	}
	return (max);
}
