#include "./includes/ft_printf.h"
#include <stdio.h>

int main()
{
	int ret_printf = 0;
	int ret_ft_printf = 0;


	printf("Outputs:\n");

	// og_len = printf("%.5d\n", 123.5);
	// my_len = ft_printf("%.5d\n", 123.5);
	// og_len = printf("[ This is %10.*u ]\n", 6, 168);
	// my_len = ft_printf("[ This is %10.*u ]\n", 6, 168);
	ret_printf = printf("Standard printf   : [ % d ]\n", -14);        
    	ret_ft_printf = ft_printf("Custom ft_printf  : [ % d ]\n", -14);   
    	printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);


	// printf("Summary:\nOG: [%i]\nMY: [%i]\n", og_len, my_len);
}
