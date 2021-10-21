/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:42 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/17 13:07:47 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	digit_len(long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (i == 0)
		++i;
	return (i);
}

static char	*negative(long int n)
{
	char	*neg;
	int		i;

	n = n * (-1);
	neg = (char *)malloc(sizeof(char) * (digit_len(n) + 2));
	if (neg == NULL)
		return (NULL);
	i = digit_len(n);
	neg[0] = '-';
	neg[i + 1] = '\0';
	while (i >= 1)
	{
		neg[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (neg);
}

char	*ft_itoa(int n)
{
	char		*answ;
	int			i;
	long int	pars;

	pars = (long int)n;
	if (n < 0)
		return (negative(pars));
	answ = (char *)malloc(sizeof(char) * (digit_len(pars) + 1));
	if (answ == NULL)
		return (NULL);
	i = digit_len(pars) - 1;
	answ[i + 1] = '\0';
	while (i >= 0)
	{
		answ[i] = (pars % 10) + '0';
		i--;
		pars = pars / 10;
	}
	return (answ);
}
