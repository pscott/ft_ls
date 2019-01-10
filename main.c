#include "ft_printf.h"
#include <unistd.h>

int	main(void)
{
	ft_putstr("\x1b[31m""Salut\n""\x1b[0m");
	write(1, "\x1b[31m", 5);
	write(1, "Salut\n", 6);
	write(1, "\x1b[0m", 4);
}
