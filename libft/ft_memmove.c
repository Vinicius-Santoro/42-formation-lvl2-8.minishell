/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:41:51 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:41:51 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_move(char *dst1, char *src1, size_t n)
{
	size_t	count;

	if (dst1 > src1)
	{
		n -= 1;
		while ((int)n >= 0)
		{
			dst1[n] = src1[n];
			n--;
		}
	}
	else
	{
		count = 0;
		while (count < n)
		{
			dst1[count] = src1[count];
			count++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst1 = (char *) dest;
	src1 = (char *) src;
	my_move(dst1, src1, n);
	return (dest);
}
