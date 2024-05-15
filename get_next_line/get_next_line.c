#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strcpy(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}


char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char	*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read(fd, buf, BUFFER_SIZE);
}

int main(void)
{
    int fd;
    char *s;

   fd = open("test.txt", O_RDONLY);
   s = get_next_line(fd);
   printf("%s", s);
   free(s);
}
