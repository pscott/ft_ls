#include <unistd.h>

int	main(void)
{
	write(1, "\x1b[31m", 5);
	write(1, "Salut\n", 6);
	write(1, "\x1b[0m", 4);
}
