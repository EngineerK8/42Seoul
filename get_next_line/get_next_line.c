/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2020/10/12 17:25:26 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#include "get_next_line.h"
#define		BUFFER_SIZE	6
int	checknl(char *s)
{
	int	cnt;

	cnt = 0;
	while(s[cnt])
	{
		if (s[cnt] == '\n')
			return (cnt);
		cnt++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int cnt;

	cnt = 0;
	while (s[cnt++])
		;
	return (cnt);
}

char	*ft_strjoin(char *dst, char *src, size_t n)
{
	int		dst_len;
	int		src_len;
	char	*s;
	int		cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;

	if (src == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!(s = (char *)malloc((dst_len + src_len + 1) * sizeof(char))))
		return (NULL);
	while (dst[cnt2])
		s[cnt++] = dst[cnt2++];
	cnt2 = 0;
	while (src[cnt2])
		s[cnt++] = src[cnt2++];
	s[dst_len + src_len] = 0;
	return (s);
}

char	*get_next_line(int fd, char **line)
{
	int			cnt;
	char		*buff;
	ssize_t		rd_size;
	static char	*backup;
	static char	*temp;

	buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	backup = (char *)malloc(BUFFER_SIZE * 256 * sizeof(char));
	rd_size = read(fd, buff, BUFFER_SIZE);
	backup = ft_strjoin(backup, buff, BUFFER_SIZE);
	printf("backup : %s\n", backup);
	printf("checknl : %d\n", checknl(backup));
	while (checknl(backup) == 0)
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		backup = ft_strjoin(backup, buff, rd_size);
	}
	//rd_size = read(fd, buff, BUFFER_SIZE);
	//temp = buff;
	//backup = ft_strjoin(backup, buff, rd_size);
	printf("backup : %s\n", backup);
	//printf("temp : %s\n", temp);


//	check_newline;
//	line malloc;

//	backup size?

	cnt = 0;
	return (backup);
}

int	main()
{
	char	buff[BUFFER_SIZE];
	char	buff2[BUFFER_SIZE];
	int		fd;
	char	**s;
	int		cnt;

	s = (char **)malloc(256 * sizeof(char *));
	cnt = 0;
	if (0 < (fd = open("./test", O_RDONLY)))
	{
		if(!(s[cnt] = (char *)malloc(4096 * sizeof(char*))))
			return (0);
		s[cnt] = get_next_line(fd, s);
		printf("%s\n", s[cnt]);
		close(fd);
		cnt++;
	}
	else
		printf("파일 열기에 실패했습니다. \n");
	return (0);
}
