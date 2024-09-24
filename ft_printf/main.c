#include "./includes/ft_printf.h"
#include <stdio.h>

int main()
{
	int og_len = 0;
	int my_len = 0;


	printf("Outputs:\n");

	og_len = printf("%s\n", NULL);
	my_len = ft_printf("%s\n", NULL);
	// og_len = printf("[ This is %10.*u ]\n", 6, 168);
	// my_len = ft_printf("[ This is %10.*u ]\n", 6, 168);

	printf("Summary:\nOG: [%i]\nMY: [%i]\n", og_len, my_len);
}
