/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:06:19 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 13:06:30 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	if (c >= 256)
		c = c - 256;
	result = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (result[i] == c)
		{
			return (&result[i]);
		}
		i--;
	}
	return (NULL);
}
