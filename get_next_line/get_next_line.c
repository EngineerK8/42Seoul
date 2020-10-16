/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:11:50 by hekang            #+#    #+#             */
/*   Updated: 2020/10/16 17:28:04 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		befree(char **str)
{
	if (*str)
		free(*str);
	return (-1);
}

int		return_all(char **backup, char **line, int rd_size, int idx)
{
	char	*temp;

	if (rd_size < 0)
		return (-1);
	if (!*backup)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if (idx != -1)
		(*backup)[idx] = 0;
	if (!(*line = ft_strdup(*backup)))
		return (befree(backup));
	if (rd_size == 0 && idx == -1)
	{
		free(*backup);
		*backup = 0;
		return (0);
	}
	if (!(temp = ft_strdup(*backup + idx + 1)))
		return (befree(backup));
	free(*backup);
	*backup = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	int			idx;
	char		*temp;

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	while (((idx = checknl(backup[fd])) != -1) &&
		((rd_size = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		if (backup[fd] == NULL)
			temp = ft_strdup(buff);
		else
			temp = ft_strjoin(backup[fd], buff);
		if (!temp)
			return (befree(&backup[fd]));
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		free(backup[fd]);
		backup[fd] = temp;
		if ((idx = checknl(backup[fd])) != -1)
			break ;
	}
	return (return_all(&backup[fd], line, rd_size, idx));
}
