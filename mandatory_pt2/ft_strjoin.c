/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:44:50 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 13:54:17 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

static void	*ft_calloc(size_t nmemb, size_t object_size)
{
	char	*ptr;

	ptr = NULL;
	ptr = (char *)malloc(nmemb * object_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, (nmemb * object_size));
	return (ptr);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = ft_strlen(dst);
	result = i;
	j = 0;
	while (src[j] != '\0' && i < (dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < result)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = NULL;
	result = (char *)ft_calloc(size, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcat(result, s1, size);
	ft_strlcat(result, s2, size);
	result[size - 1] = '\0';
	return (result);
}
