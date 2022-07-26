/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:41:42 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:41:42 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	count = 0;
	while (a[count] == b[count] && count < (n - 1))
		count++;
	if (n == 0)
		return (0);
	return (a[count] - b[count]);
}
