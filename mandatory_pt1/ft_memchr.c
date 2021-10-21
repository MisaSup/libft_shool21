/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:15:13 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 13:15:29 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	char	*result;
	size_t	i;

	if (c >= 256)
		c = c - 256;
	result = (char *)s;
	i = 0;
	while (i < n)
	{
		if (result[i] == c)
		{
			return (&result[i]);
		}
		i++;
	}
	return (NULL);
}
