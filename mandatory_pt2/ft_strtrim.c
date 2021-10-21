/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:51:44 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/17 12:49:46 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	char	*result;
	int		i;

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

char	*ft_strtrim(char const *s1, char const *set)
{	
	int		start;
	int		end;
	int		i;
	char	*res;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	res = (char *)malloc(sizeof(char) * (end - start + 2));
	if (res == NULL)
		return (NULL);
	res[end - start + 1] = '\0';
	end = end - start;
	i = -1;
	while (i < end)
		res[++i] = s1[start++];
	return (res);
}
