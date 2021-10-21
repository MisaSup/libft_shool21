/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:03:11 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 13:06:10 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	int		i;

	if (c >= 256)
		c = c - 256;
	result = (char *)s;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] == c)
		{
			return (&result[i]);
		}
		i++;
	}
	if (c == '\0')
		return (&result[i]);
	return (NULL);
}
