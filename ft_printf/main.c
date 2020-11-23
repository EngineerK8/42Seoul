#include <stdio.h>
#include "ft_printf.h"

int main()
{
printf("--------------------------\n");
	printf("%%7d, -14 : %7d\n", -14);
	ft_printf(" : %7d\n", -14);
	printf("%%.6d, -3 : %.6d\n", -3);
	ft_printf(" : %.6d\n", -3);
	printf("%%.05d, 43 : %.05d\n", 43);
	ft_printf(" : %.05d\n", 43);
	printf("%%07d, -54 : %07d\n", -54);
	ft_printf(" : %07d\n", -54);
	printf("%%10.5d, 54 : %10.5d.\n", 54);
	ft_printf(" : %10.5d.\n", 54);
	printf("%%10.5d, -54\n : %10.5d.\n", -54);
	ft_printf(" : %10.5d\n", -54);
	printf("%%-8.5d, 54\n : _%-8.5d.\n", 54);
	ft_printf(" : _%-8.5d.\n", 54);
	printf("%%-11.5d, 54\n : _%-11.5d.\n", 54);
	ft_printf(" : _%-11.5d.\n", 54);
	printf("%%-3.5d, 54\n : _%-3.5d.\n", 54);
	ft_printf(" : _%-3.5d.\n", 54);
	printf("%%-5.5d, 54\n : _%-5.5d.\n", 54);
	ft_printf(" : _%-5.5d.\n", 54);
	printf("%%-1.1d, 54\n : _%-1.1d.\n", 54);
	ft_printf(" : _%-1.1d.\n", 54);

	printf("--------------------------\n");

	printf("%%08.5d, 34 : %08.5d\n", 34);
	ft_printf("%%08.5d, 34 : %08.5d\n", 34);

	int a;
	int b;

	a = printf("%-7i\n", 33);
	b = ft_printf("%-7i\n", 33);

	printf("a: %d, b: %d\n", a, b);
}


