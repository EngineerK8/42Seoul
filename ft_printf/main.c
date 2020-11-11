#include <stdio.h>
#include "ft_printf.h"

int main()
{
printf("--------------------------\n");
	printf("%7d\n", -14);
	ft_printf("%7d\n", -14);
	printf("%.6d\n", -3);
	ft_printf("%.6d\n", -3);
	printf("%.05d\n", 43);
	ft_printf("%05d\n", 43);
	printf("%07d\n", -54);
	ft_printf("%07d\n", -54);
	printf("%10.5d\n", 54);
	ft_printf("%10.5d\n", 54);
	printf("%10.5d\n", -54);
	ft_printf("%10.5d\n", -54);
	printf("%-8.5d\n", 54);
	ft_printf("%-8.5d\n", 54);
printf("--------------------------\n");

	printf("%08.5d\n", 34);
	ft_printf("%08.5d\n", 34);
}


