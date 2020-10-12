/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:24:04 by hekang            #+#    #+#             */
/*   Updated: 2020/10/10 16:22:27 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>         // puts()
#include <string.h>        // strlen()
#include <fcntl.h>         // O_RONLY
#include <unistd.h>        // write(), close()
#include <stdlib.h>

#define  BUFF_SIZE   6     // 버퍼의 크기가 작습니다.

// OPEN_MAX
/*int main()
{
	char	buff[BUFF_SIZE];
	int		fd;
	ssize_t	rd_size;

   if (0 < (fd = open("./test", O_RDONLY)))
   {
    printf("fd : %d\n", fd);
      while(0 < (rd_size = read(fd, buff, BUFF_SIZE-1)))   //  4 byte씩 읽씁니다.
      {
         printf("rd size : %zd\n", rd_size);
         buff[rd_size]  = '\0';      // puts()를 위해 NULL을 대입
         printf("%s\n", buff);
      }
      close(fd);
   }
   else
   {
      printf("파일 열기에 실패했습니다.\n");
   }
   return (0);
}*/
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	cnt;

	if (dst == 0 && src == 0)
		return (dst);
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
		cnt++;
	}
	return (dst);
}
char    *ft_strjoin(char const *s1, char const *s2)
 {
      int     len1;
      int     len2;
      char    *str;
 
     len1 = strlen(s1);
      len2 = strlen(s2);
      str = calloc(len1 + len2 + 1, sizeof(char));
      if (!str)
          return (0);
      ft_memcpy(str, s1, len1);
      ft_memcpy(str + len1, s2, len2 + 1);
      return (str);
 }
int main()
{
   char   buff[BUFF_SIZE];
   char   buff2[BUFF_SIZE];
   int    fd;
   static char		*tmp;
   static char	*backup;
	ssize_t rd_size;

   if ( 0 < ( fd = open( "./test", O_RDONLY)))
   {
      rd_size = read( fd, buff, BUFF_SIZE);
	  tmp = buff;
      rd_size = read( fd, tmp, BUFF_SIZE);
	  //	  temp = ft_strjoin(temp, buff);
//      printf("backup : %lu\n", strlen(temp));
      printf("backup : %s\n", backup);
	  printf("rd_size : %zd\n", rd_size);
//	  rd_size = read( fd, buff, BUFF_SIZE);
//	  printf("backup : %s\n", backup);
//	  rd_size = read( fd, temp, BUFF_SIZE);
	  printf("temp : %s\n", tmp);
	  printf("rd_size : %zd\n", rd_size);
      puts( buff);
      close( fd);
   }
   else
   {
      printf( "파일 열기에 실패했습니다.\n");
   }
   return 0;
}
