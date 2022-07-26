/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:44:04 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:44:04 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (c > 255)
		c -= 256;
	while (*s != '\0')
	{
		s++;
		a++;
	}
	while (a >= 0)
	{
		if (*s == c)
			return ((char *) s);
		s--;
		a--;
	}
	return (NULL);
}
