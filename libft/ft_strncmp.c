/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:43:51 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:43:51 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (s1[a] == s2[a] && s1[a] != '\0' && a < (n - 1))
	{
		a++;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char) s1[a] - (unsigned char) s2[a]);
}
