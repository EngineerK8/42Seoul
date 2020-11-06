/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:36 by hekang            #+#    #+#             */
/*   Updated: 2020/11/06 17:37:15 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int	initdata(t_data d)
{
	d.type = 0;
	d.value = 0;
	d.sign = 1;
	d.width	= 0;
	d.flags = 0;
	d.preci = 0;
	d.size = 0;
	return (1);
}


int	checkflag(char *str, int i) // -, 0, . *
{
	int j;

	j = 0;
	if (str[j] == '-')
		is_minus = 1;

	checkminus();	//left align
	checkzero();	//왼쪽에 0
	checkprecision();	
	return (0);
}



int	ft_printf(const char *types, ...)
{
//	t_data	*data;
	t_data	tdata;
	int i;
	
//	initdata(data);

	i = 0;
	va_start(tdata.valist, types);
	while (types[i])
	{
		if (types[i + 1] &&types[i] == '%')
		{
			i = checkflag(&types[i], i);

			if (types[i + 1] == 'd')
				ft_putnbr(va_arg(tdata.valist, int));
			if (types[i + 1] == 'c')
				ft_putchar(va_arg(tdata.valist, int));
			if (types[i + 1] == 's')
				ft_putstr(va_arg(tdata.valist, char *));
			if (types[i + 1] == 'X')
				ft_puthexa(va_arg(tdata.valist, int), 1);
			if (types[i + 1] == 'x')
				ft_puthexa(va_arg(tdata.valist, int), 2);
			if (types[i + 1] == 'p')
				ft_putpointer((long long)va_arg(tdata.valist, void *));
			if (types[i + 1] == 'u')
				ft_putunbr(va_arg(tdata.valist, int));
			i++;			
		}
		else
			write(1, &types[i], 1);
		i++;
	}
	va_end(tdata.valist);
	return (0);
}

int main()
{
	int a;
	int b;

	a = 0;
	ft_printf("123 %d\nabc %s\na %c\n", 123, "abc", 'a');
	ft_printf("%X, %x \n", -1, 123);
	ft_printf("pointer : %p\n", &a);
	printf("pointer : %p\n", &a);
	
	ft_printf("d: %d\n", -1);
	ft_printf("u: %u\n", -1);

	printf("u: %u\n", -1);

	printf("%06d\n", 1);
	printf("%0.00005d\n", 1);
	printf("%-----5d\n", 1);
	printf("%-.5d\n", 1);
	printf("%10.2d\n", 1);
/*
	printf("%-5d\n", 1);
	printf("%5d\n", 1);
	printf("%06d\n", 1);
	printf("%-.01f\n", 1.12);

	printf("%x\n", 123);
	ft_puthexa(123, 1);
	ft_puthexa(123, 2);
*/

	printf("%u\n", -1);
	printf("%i\n", -1);
	printf("%d\n", -1);
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
