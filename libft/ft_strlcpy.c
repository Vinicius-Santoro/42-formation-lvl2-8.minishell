/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:43:35 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:43:35 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	b = 0;
	a = 0;
	while (src[b] != '\0')
		b++;
	if (size != 0)
	{
		while (a < (size - 1) && src[a] != '\0')
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (b);
}
