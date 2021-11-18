#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int	main(void)
{

	int	fd;
	// //https://github.com/rchallie/get_next_line.git
	fd = open("gnlTester/files/41_no_nl", O_RDONLY);

	printf("%s-", get_next_line(3));
	printf("%s", get_next_line(3));
}