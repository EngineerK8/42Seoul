/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2020/10/13 23:31:48 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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

//	if (src == 0)
//		return (0);
	dst_len = ft_strlen(dst);
	src_len = checknl(src) > 0 ? checknl(src) : ft_strlen(src);
	if (!(s = (char *)malloc((dst_len + src_len + 1) * sizeof(char))))
		return (NULL);
	while (dst[cnt2])
		s[cnt++] = dst[cnt2++];
	cnt2 = 0;
	while (src[cnt2] && cnt2 <= n)
		s[cnt++] = src[cnt2++];
//	s[dst_len + (src_len > n ? src_len : n)] = 0;
	return (s);
}

void	ft_revjoin(char *backup, char *src, size_t n)
{
	int		src_len;
	char	*s;
	int		cnt;

	cnt = 0;
	src_len = ft_strlen(src);
	(backup = (char *)malloc((n + 1) * sizeof(char)));
	while (cnt < n)
	{
		backup[cnt] = src[src_len - n + cnt + 1];
		cnt++;
	}
}

int		get_next_line(int fd, char **line)
{
	//OPEN_MAX fd 최대값
	char		*buff;
	ssize_t		rd_size;
	static char	*backup[OPEN_MAX];
	char		*temp;

	printf("backup : %s\n", backup[fd]);
	buff = (char *)malloc(BUFFER_SIZE * 256 * sizeof(char));
	temp = (char *)malloc(BUFFER_SIZE * 256 * sizeof(char));
	rd_size = read(fd, buff, BUFFER_SIZE);
	temp = ft_strjoin(temp, buff, BUFFER_SIZE);
//	printf("backup : %s\n", buff);
	if (rd_size < BUFFER_SIZE)
		return (0);
	while (checknl(temp) == 0)
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		temp = ft_strjoin(temp, buff, checknl(buff) == 0 ? rd_size : checknl(buff));
//		printf("rd_size : %zd\n", rd_size);
//		printf("checknl(buff) : %d\n", checknl(buff));
	}
	ft_revjoin(backup[fd], buff, BUFFER_SIZE - rd_size);
//	printf("buff : %s\n", buff);
//	printf("rd_size : %zd\n", rd_size);
//	printf("chcknl(buff) : %d\n", checknl(buff));
	printf("	revjoin : %s\n", backup[fd]);
	backup[fd][ft_strlen(backup[fd]) - 1] = 0;
	temp[ft_strlen(temp)-2] = 0;
	line[fd] = temp;
	return (1);
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
		get_next_line(fd, s);
		printf("%s\n", s[fd]);
		get_next_line(fd, s);
		printf("%s\n", s[fd]);
		get_next_line(fd, s);
		printf("%s\n", s[fd]);
		get_next_line(fd, s);
		printf("%s\n", s[fd]);
		close(fd);
		cnt++;
	}
	else
		printf("파일 열기에 실패했습니다. \n");
	return (0);
}
