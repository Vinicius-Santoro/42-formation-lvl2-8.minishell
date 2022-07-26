/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:41:46 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:41:46 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*a;
	char	*b;

	if (dest == NULL && src == NULL)
		return (NULL);
	a = (char *)dest;
	b = (char *)src;
	count = 0;
	while (count < n)
	{
		a[count] = b[count];
		count++;
	}
	return (dest);
}
