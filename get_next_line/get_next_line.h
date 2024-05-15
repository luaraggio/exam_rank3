#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE 10
# define BUFFER_SIZE 10
#endif

char    *get_next_line(int fd);

#endif
