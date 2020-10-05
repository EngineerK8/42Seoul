/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:37:53 by hekang            #+#    #+#             */
/*   Updated: 2020/10/05 02:21:32 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		p1;
	int		p2;
	char	*str;
	char	*str2;
	int		cnt;
	int		cnt2;
	int		tcnt;

	cnt = 0;
	tcnt = 0;
	str = (char *)malloc(ft_strlen(s1) * sizeof(char));
	while(s1[cnt])
	{
		cnt2 = 0;
		if (s1[cnt] == set[cnt2])
		{
			while (set[cnt2])
			{
				if (s1[cnt + cnt2] != set[cnt2])
					break;
				cnt2++;
				if (set[cnt2] == 0)
				{
					ft_memcpy(str, s1, cnt)
					ft_memcpy(str, 
					cnt = 0;
			}
		}
		cnt++;
	}
