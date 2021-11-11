#include "head.h"

int	main(void)
{
	int	fd;
	//https://github.com/rchallie/get_next_line.git
	fd = open("test", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
