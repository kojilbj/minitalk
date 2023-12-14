#include <stdio.h>

int	main(int ac, char *av[])
{
	if(ac != 2)
		return 0;
	printf("%s\n", av[1]);
	return 0;
}
