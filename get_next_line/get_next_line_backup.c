/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2020/10/16 10:49:05 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>


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
	char		*temp;

	rd_size = 0;
	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	if ((idx = checknl(backup[fd])) == -1)
		while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			if (backup[fd] == NULL)
				temp = ft_strdup(buff);
			else
				temp = ft_strjoin(backup[fd], buff);
			if (!temp)
			{
				if (backup[fd])
					free(backup[fd]);
				return (-1);
			}
			ft_memset(buff, 0, BUFFER_SIZE + 1);
			free(backup[fd]);
			backup[fd] = temp;
			if ((idx = checknl(backup[fd])) != -1)
				break ;
		}
	if (rd_size < 0)
		return (-1);
	if (!backup[fd])
	{
		if(!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if (idx != -1)
		backup[fd][idx] = 0;
	*line = ft_strdup(backup[fd]);
/*	if (!(*line = ft_strdup(backup[fd])))
	{
		if (backup[fd])
			free(backup[fd]);
		return (-1);
	}*/
	if (rd_size == 0 && idx == -1)
	{
		free(backup[fd]);
		backup[fd] = 0;
		return (0);
	}
	temp = ft_strdup(backup[fd] + idx + 1);
/*	if (!(temp = ft_strdup(backup[fd] + idx + 1)))
	{
		if (backup[fd])
			free(backup[fd]);
		return (-1);
	}*/
	free(backup[fd]);
	backup[fd] = temp;
	return (1);
}
