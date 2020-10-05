/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:18:23 by hekang            #+#    #+#             */
/*   Updated: 2020/10/05 19:35:29 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		cnt;
	char	*result;

	cnt = 0;
	while (s[cnt])
	{
		if ((unsigned char)(s[cnt]) == start)
		{
			result = (char *)ft_calloc(len + 1, sizeof(char));
			ft_memcpy(result, s, len + 1);
			return (result);
		}
		cnt++;
	}
	return (NULL);
}
