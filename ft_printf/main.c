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


	a = -4;
	b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	ft_printf(" --- ft_Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2

	printf(" --- Return : %d\n", printf("%i", i));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%i", i));
	printf(" --- Return : %d\n", printf("%d", j));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%d", j));
	printf(" --- Return : %d\n", printf("%d", k));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%d", k));
	printf(" --- Return : %d\n", printf("%d", l));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%d", l));

	printf(" --- Return : %d\n", printf("%d", m));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%d", m));
	printf(" --- Return : %d\n", printf("%s", n));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%d", n));
	printf(" --- Return : %d\n", printf("%c", c));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%c", c));
	printf(" --- Return : %d\n", printf("%d", c));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%d", c));


	printf("--------------------------\n");
	printf(" --- Return : %d\n", printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j,     k, l, m, c, e, d)); //T3
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j,     k, l, m, c, e , d)); //T3

	printf(" --- Return : %i\n", printf("%0i", i));
	ft_printf(" --- ft_Return : %i\n", ft_printf("%0i", i));
	printf(" --- Return : %d\n", printf("%0d", j));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", j));
	printf(" --- Return : %d\n", printf("%0d", k));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", k));
	printf(" --- Return : %d\n", printf("%0d", l));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", l));

	printf(" --- Return : %d\n", printf("%0d", m));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", m));
	printf(" --- Return : %d\n", printf("%0d", c));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", c));

	printf(" --- Return : %d\n", printf("%0d", e));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", e));
	printf(" --- Return : %d\n", printf("%0d", d));
	ft_printf(" --- ft_Return : %d\n", ft_printf("%0d", d));



	printf("--------------------------\n");
	printf("--------------------------\n");
printf(" --- Return : %d\n", printf("%0.i, %0.d, %0.d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d));
ft_printf(" --- ft_Return : %d\n", ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d));


	a = -2;
	int aa = 70;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			printf(" --- Return : %d\n", printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			printf(" --- Return : %d\n", printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			printf(" --- Return : %d\n", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			ft_printf(" --- ft_Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			ft_printf(" --- ft_Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			ft_printf(" --- ft_Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			b++;
			aa += 3;
			printf("\na : %d, b : %d", a, b);
			printf("\nTEST %d \n", aa);
		}
		a++;
	}
	a = 2;
	b = -1;

	printf("\n\n\n");
	printf("%%0a.bd // a = %d, b = %d\n",a, b);
	printf("-----------Return : %d\n", printf("%0*.*d, %0*.*d", a, b, i, a, b, l));
	printf("-----------ftReturn : %d\n", ft_printf("%0*.*d, %0*.*d", a, b, i, a, b, l));

	a = 2;
	b = 0;
	printf("\n\n\n");
	printf("%%0a.bd // a = %d, b = %d\n",a, b);
	printf("-----------Return : %d\n", printf("%0*.*d, %0*.*d", a, b, i, a, b, l));
	printf("-----------ftReturn : %d\n", ft_printf("%0*.*d, %0*.*d", a, b, i, a, b, l));

	a = 3;
	b = 0;
	printf("\n\n\n");
	printf("%%0a.bd // a = %d, b = %d\n",a, b);
	printf("-----------Return : %d\n", printf("%0*.*d, %0*.*d", a, b, i, a, b, l));
	printf("-----------ftReturn : %d\n", ft_printf("%0*.*d, %0*.*d", a, b, i, a, b, l));

	a = 3;
	b = 0;
	printf("\n\n\n");
	printf("%%0ad // a = %d, b = %d\n",a, b);
	printf("-----------Return : %d\n", printf("%0*d, %0*d", a, i, a, l));
	printf("-----------ftReturn : %d\n", ft_printf("%0*d, %0*d", a, i, a, l));

	
	a = 0;
	b = 2;
	printf("\n\n\n");
	printf("%%0a.bd // a = %d, b = %d\n",a, b);
	printf("-----------Return : %d\n", printf("%0*.*d, %0*.*d", a, b, i, a, b, l));
	printf("-----------ftReturn : %d\n", ft_printf("%0*.*d, %0*.*d", a, b, i, a, b, l));





}


