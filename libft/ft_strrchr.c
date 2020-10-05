/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:11:56 by hekang            #+#    #+#             */
/*   Updated: 2020/10/02 22:15:52 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cnt;
	int lcnt;

	cnt = 0;
	while (s[cnt])
	{
		if (s[cnt] == c)
			lcnt = cnt;
		cnt++;
	}
	return (s + lcnt);
}
