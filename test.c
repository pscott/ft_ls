#include "ft_ls.h"

int	main(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 10);
	ft_strcpy(str, "1234567890");
	printf("%s\n", str);
	return (0);
}
