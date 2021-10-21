/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:18:13 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 14:18:26 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*answ;
	unsigned int	i;

	answ = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (answ == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		answ[i] = (*f)(i, s[i]);
		i++;
	}
	answ[i] = '\0';
	return (answ);
}
