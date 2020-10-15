/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2020/10/15 09:36:05 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "get_next_line_bonus.h"

int		checknl(char *s)
{
	int	cnt;

	cnt = 0;
	if (s == 0)
		return (-1);
	while (s[cnt])
	{
		if (s[cnt] == '\n')
			return (cnt);
		cnt++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	int			idx;

	if ((idx = checknl(backup[fd])) == -1)
		while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			if (backup[fd] == NULL)
				backup[fd] = ft_strdup(buff);
			else
			{
				backup[fd] = ft_strjoin(backup[fd], buff);
				if ((idx = checknl(backup[fd])) != -1)
					break ;
			}
		}
	backup[fd][idx] = 0;
	if (!(*line = ft_strdup(backup[fd])))
		return (-1);
	backup[fd] = ft_strdup(backup[fd] + idx + 1);
	if (rd_size == 0)
		return (0);
	return (1);
}

int		main(void)
{
	int		fd;
	char	*s;

	if (0 < (fd = open("./test", O_RDONLY)))
	{
		while (get_next_line(fd, &s) != 0)
			printf("%s\n", s);
		close(fd);
	}
	else
		printf("파일 열기에 실패했습니다. \n");
	return (0);
}
