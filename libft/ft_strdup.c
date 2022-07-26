/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:43:08 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:43:08 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*a;
	int		b;
	int		count;

	count = 0;
	while (s[count] != '\0')
		count++;
	a = (char *) malloc((count + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	b = 0;
	while (s[b] != '\0')
	{
		a[b] = s[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}
