/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:36 by hekang            #+#    #+#             */
/*   Updated: 2020/11/10 17:45:19 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int	initdata(t_dataopt *dataopt)
{
	dataopt->dwidth = 0;
	dataopt->isleft = 0;
	dataopt->iszero = 0;
	dataopt->preci = 0;
	return (1);
}

int	isparam(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'X' ||
			c == 'X' || c == 'p' || c == 'u')
		return (1);
	return (0);
}

int	isminus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	iszero(char s)
{
	if (s == '0')
		return (1);
	return (0);
}

int	ispoint(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	isstar(char c)
{
	if (c == '*')
		return (1);
	return (0);
}

void	checkflag(char **str,t_dataopt *dataopt) // -, 0, . *
{
	int j;

	j = 0;
	while (isminus(**str) || iszero(**str))
	{
		if (isminus(**str))
			dataopt->isleft = 1;
		dataopt->iszero = 1;	
		(*str)++;
	}
	if (dataopt->isleft && dataopt->iszero)
		dataopt->iszero = 0;
}

void	checkwidth(char **str, t_dataopt *dataopt)
{
	int	bstar;

	bstar = 0;
	while (isstar(**str))
	{
		dataopt->dwidth = va_arg(dataopt->valist, int);
		(*str)++;
		bstar = 1;
	}
	while (ft_isdigit(**str))
	{
		if (bstar == 1)
			dataopt->dwidth = 0;		
		bstar = 0;
		dataopt->dwidth = dataopt->dwidth * 10 + **str - '0';
		(*str)++;
	}
}

void	checkprecision(char **str, t_dataopt *dataopt)
{
	if (!ispoint(**str))
		return ;
	(*str)++;
	while (ft_isdigit(**str))
	{
		dataopt->preci = dataopt->preci * 10 + **str - '0';
		(*str)++;
	}
}


int	isrightcont(char *str)
{
	if (*str == '%')
		str++;
	while ((*str) == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (ispoint(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	while (isparam(*str))
		return (1);
	return (0);
}

int	ft_nbrlen(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_nbrhexalen(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void inputpad(char cpad, int n)
{
	while (n && n > 0)
	{
		write(1, &cpad, 1);
		n--;
	}
}

void	 print_with_padding_d(t_dataopt *dopt, int n, int wid)
{
	if (dopt->isleft)
	{
		ft_putnbr(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putnbr(n);
	}
	else
		ft_putnbr(n);
	printf("\ndopt->dwidth : %d\n", dopt->dwidth);
	printf("\ndopt->preci : %d\n", dopt->preci);
	printf("\nwidth : %d\n", wid);
}

void	 print_with_padding_c(t_dataopt *dopt, int n, int wid)
{
	if (dopt->isleft)
	{
		ft_putchar(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putchar(n);
	}
	else
		ft_putchar(n);
	printf("\ndopt->dwidth : %d\n", dopt->dwidth);
	printf("\ndopt->preci : %d\n", dopt->preci);
	printf("\nwidth : %d\n", wid);
}

int ft_print_d(t_dataopt *dopt, int n)
{
	int wid;

	wid = ft_nbrlen(n);
	if (dopt->isleft)
	{
		ft_putnbr(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putnbr(n);
	}
	else
		ft_putnbr(n);
	return (1);
}

int ft_print_c(t_dataopt *dopt, int n)
{
	int wid;

	wid = 1;
	if (dopt->isleft)
	{
		ft_putchar(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth -  wid);
		ft_putchar(n);
	}
	else
		ft_putchar(n);
	return (1);
}

int ft_print_s(t_dataopt *dopt, char *s)
{
	int wid;

	wid = ft_strlen(s);
	if (dopt->isleft)
	{
		ft_putstr(s);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > (dopt->preci < wid ? dopt->preci : wid))
	{
		inputpad(' ', dopt->dwidth - wid);
		ft_putstr(s);
	}
	else
		ft_putstr(s);
	return (1);
}

int	ft_print_x(t_dataopt *dopt, int n, int type)
{
	int	wid;

	wid = ft_nbrhexalen(n);
	if (dopt->isleft)
	{
		ft_puthexa(n, type);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_puthexa(n, type);
	}
	else
		ft_puthexa(n, type);
	return (1);
}

int ft_print_p(t_dataopt *dopt, long long n)
{
	int wid;

	wid = 14;
	if (dopt->isleft)
	{
		ft_putpointer(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putpointer(n);
	}
	else
		ft_putpointer(n);
	return (1);
}
int ft_print_u(t_dataopt *dopt, int n)
{
	int wid;

	wid = ft_nbrlen(n);
	if (dopt->isleft)
	{
		ft_putunbr(n);
		inputpad(' ', dopt->dwidth - wid);
	}
	else if (dopt->dwidth > wid)
	{
		inputpad(' ', dopt->dwidth - (dopt->preci > wid ? dopt->preci : wid));
		if (dopt->preci > wid)
			inputpad('0', dopt->preci - wid);
		ft_putunbr(n);
	}
	else
		ft_putunbr(n);
	return (1);
}

int	ft_printf(const char *types, ...)
{
//	t_data	*data;
	char		*str;
	t_dataopt	dataopt;
	int			i;
	
//	initdata(data);

	i = 0;
	va_start(dataopt.valist, types);
	str = (char *)types;
	while (*str)
	{
		initdata(&dataopt);
//			printf("isrightcont : %d\n", isrightcont(str));
		if (*(str + 1) && *str == '%' && isrightcont(str))
		{
			str++;
			checkflag(&str, &dataopt);
			checkwidth(&str, &dataopt);
			checkprecision(&str, &dataopt);


			
			if (*str == 'd' || *str == 'i')
				ft_print_d(&dataopt, va_arg(dataopt.valist, int));
			if (*str == 'c')
				ft_print_c(&dataopt, va_arg(dataopt.valist, int));
			if (*str == 's')
				ft_print_s(&dataopt, va_arg(dataopt.valist, char *));
			if (*str == 'X')
				ft_print_x(&dataopt, va_arg(dataopt.valist, int), 1);
			if (*str == 'x')
				ft_print_x(&dataopt, va_arg(dataopt.valist, int), 2);
			if (*str == 'p')
				ft_print_p(&dataopt, (long long)va_arg(dataopt.valist, void *));
			if (*str == 'u')
				ft_print_u(&dataopt, va_arg(dataopt.valist, int));
//			str++;			
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(dataopt.valist);
	return (0);
}

int main()
{
	int a;
	int b;

	a = 0;
	ft_printf("123 %d\nabc %c%s\na %c%----d\n", 123, 'a',"abc", 'a', 13);
//	ft_printf("%X, %x \n", -1, 123);
//	ft_printf("pointer : %p\n", &a);
	printf("pointer : %p\n", NULL);
	
	ft_printf("pointer : %p\n", NULL);
	
//	ft_printf("d: %d\n", -1);
//	ft_printf("u: %u\n", -1);

//	printf("u: %u\n", -1);

//	printf("%06d\n", 1);
//	printf("%0.00005d\n", 1);
	printf("%0*00*0*0-000--00000000-****5d\n", 1);
//	printf("%-.5d\n", 1);
	printf("%0010.2d\n", 1);
	ft_printf("%0010.2d\n", 1);
	printf("%-5d\n", 1);
/*
	printf("%-5d\n", 1);
	printf("%5d\n", 1);
	printf("%06d\n", 1);
	printf("%-.01f\n", 1.12);

	printf("%x\n", 123);
	ft_puthexa(123, 1);
	ft_puthexa(123, 2);
*/

//	printf("%u\n", -1);
//	printf("%i\n", -1);
//	printf("%d\n", -1);
	return (0);
}

/*
void printValues(char *types, ...)    // 가변 인자의 자료형을 받음, ...로 가변 인자 설정
{
    va_list ap;    // 가변 인자 목록
    int i = 0;

    va_start(ap, types);        // types 문자열에서 문자 개수를 구해서 가변 인자 포인터 설정
    while (types[i] != '\0')    // 가변 인자 자료형이 없을 때까지 반복
    {
        switch (types[i])       // 가변 인자 자료형으로 분기
        {
        case 'i':                                // int형일 때
            printf("%d ", va_arg(ap, int));      // int 크기만큼 값을 가져옴
                                                 // ap를 int 크기만큼 순방향으로 이동
            break;
        case 'd':                                // double형일 때
            printf("%f ", va_arg(ap, double));   // double 크기만큼 값을 가져옴
                                                 // ap를 double 크기만큼 순방향으로 이동
            break;
        case 'c':                                // char형 문자일 때
            printf("%c ", va_arg(ap, int));     // char 크기만큼 값을 가져옴
                                                 // ap를 char 크기만큼 순방향으로 이동
            break;
        case 's':                                // char *형 문자열일 때
            printf("%s ", va_arg(ap, char *));   // char * 크기만큼 값을 가져옴
                                                 // ap를 char * 크기만큼 순방향으로 이동
            break;
        default:
            break;
        }
        i++;
    }
    va_end(ap);    // 가변 인자 포인터를 NULL로 초기화

    printf("\n");    // 줄바꿈
}

int main()
{
    printValues("i", 10);                                       // 정수
    printValues("ci", 'a', 10);                                 // 문자, 정수
    printValues("dci", 1.234567, 'a', 10);                      // 실수, 문자, 정수
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // 문자열, 정수, 문자, 실수

    return 0;
}*/
