#ifndef HEAD_H
# define HEAD_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER_SIZE 7
char	*get_next_line(int fd);

#endif