/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:41:35 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:41:35 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*a;

	a = (unsigned char *) s;
	count = 0;
	if (n == 0)
		return (NULL);
	while (count < n - 1)
	{
		if (*a == (unsigned char) c)
			return (a);
		count++;
		a++;
	}
	if (*a == (unsigned char) c)
		return (a);
	return (NULL);
}
