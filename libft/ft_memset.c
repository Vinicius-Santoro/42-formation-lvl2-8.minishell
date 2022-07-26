/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:41:59 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:41:59 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count;
	char		*str;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = c;
		count++;
	}
	return (str);
}
