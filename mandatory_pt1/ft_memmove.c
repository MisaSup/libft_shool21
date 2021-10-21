/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:19:20 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 12:23:59 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if ((tmp_src < tmp_dst) && (tmp_dst < tmp_src + len))
	{
		tmp_dst = tmp_dst + len;
		tmp_src = tmp_src + len;
		while (len-- && (dst || src))
			*--tmp_dst = *--tmp_src;
	}
	else
		while (len-- && (dst || src))
			*tmp_dst++ = *tmp_src++;
	return (dst);
}
