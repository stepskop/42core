#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main()
{
	char *a, *b, *c, *d, *e, *f;
	int fd = open("file.txt", O_RDONLY);
	a = get_next_line(fd);
	b = get_next_line(fd);
	c = get_next_line(fd);
	d = get_next_line(fd);
	e = get_next_line(fd);
	f = get_next_line(fd);
	// if (fd == -1)
	// 	return 1;
	printf("1: |%s|\n", a);
	printf("2: |%s|\n", b);
	printf("3: |%s|\n", c);
	printf("4: |%s|\n", d);
	printf("5: |%s|\n", e);
	printf("6: |%s|\n", f);
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	// printf("%s", get_next_line(fd));
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
}
