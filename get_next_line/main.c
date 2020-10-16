/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:06:51 by hekang            #+#    #+#             */
/*   Updated: 2020/10/16 14:15:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int		fd;
	int		eof;
	char	*s;

	if (0 < (fd = open("./test", O_RDONLY)))
	{
		while ((eof = get_next_line(fd, &s)) != 0)
		{
			printf("gnl : %s\n", s);
		}
		close(fd);
	}
	else
		printf("파일 열기에 실패했습니다. \n");
	return (0);
}
