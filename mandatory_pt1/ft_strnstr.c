/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:20:56 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/17 12:53:16 by wcarlos          ###   ########.fr       */
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

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (n);
	i = 0;
	while (i < (n - 1) && s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	check;
	size_t	i;

	check = ft_strlen(needle);
	if (check == 0)
		return ((char *)haystack);
	i = 0;
	while (i <= len && i <= ft_strlen(haystack))
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return (&((char *)haystack)[i]);
		i++;
		if (ft_strlen(needle) + i > len)
			return (NULL);
	}
	return (NULL);
}
