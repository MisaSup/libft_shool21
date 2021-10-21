/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:36:02 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 12:36:32 by wcarlos          ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t object_size)
{
	char	*ptr;

	ptr = NULL;
	ptr = (char *)malloc(nmemb * object_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, (nmemb * object_size));
	return (ptr);
}
