/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:42:36 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:42:36 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop(int b, int fd)
{
	if (b >= 10)
	{
		loop(b / 10, fd);
	}
	b = (b % 10) + 48;
	write (fd, &b, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		write (fd, "-", 1);
	}
	if (nb != -2147483648)
	{
		loop(nb, fd);
	}
	if (nb == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
}
