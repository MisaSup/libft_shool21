/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:10:27 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 16:04:07 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursion(int n, int fd)
{
	char	num;

	if (n / 10 > 0)
		recursion(n / 10, fd);
	num = (n % 10) + '0';
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	if (n != -2147483648)
		recursion(n, fd);
}
