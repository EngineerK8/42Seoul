/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2020/10/14 23:32:02 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "get_next_line.h"
#define		BUFFER_SIZE	40
int	checknl(char *s)
{
	int	cnt;

	cnt = 0;
	if (s == 0)
		return (-1);
	while(s[cnt])
	{
		if (s[cnt] == '\n')
			return (cnt);
		cnt++;
	}
	return (-1);
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
	while (src[cnt2] && cnt2 <= n)
		s[cnt++] = src[cnt2++];
//	s[dst_len + (src_len > n ? src_len : n)] = 0;
	return (s);
}

int		get_next_line2(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE+1];
	int			idx;

	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup(buff);
		else
		{
			backup[fd] = ft_strjoin(backup[fd], buff, rd_size);
			if ((idx = checknl(backup[fd])) != -1)
				break ;
		}
	}
	idx = checknl(backup[fd]);
	backup[fd][idx] = 0;
	if(!(*line = ft_strdup(backup[fd])))
		return (-1);
//	printf("backup[fd] : %s\n", backup[fd]);
//	printf("idx : %d\n", idx);
	backup[fd] = ft_strdup(backup[fd] + idx + 1);
	if (rd_size == 0)
		return (0); // EOF
	return (1);
}

int	main()
{
	int		fd;
	char	*s;

	if (0 < (fd = open("./test", O_RDONLY)))
	{
		while (get_next_line2(fd, &s) != 0)
			printf("%s\n", s);
		close(fd);
	}
	else
		printf("파일 열기에 실패했습니다. \n");
	return (0);
}
