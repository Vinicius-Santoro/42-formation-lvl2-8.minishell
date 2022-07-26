/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:44:13 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:44:13 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_count(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	a;

	a = 0;
	count = 0;
	while (s[a] != '\0')
	{
		if (a >= start && count < len)
			count++;
		a++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	count;

	a = 0;
	b = 0;
	if (len == 0)
		return (NULL);
	count = my_count(s, start, len);
	str = (char *) malloc (sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	while (s[a] != '\0')
	{
		if (a >= start && b < len)
		{
			str[b] = s[a];
			b++;
		}
		a++;
	}
	str[b] = '\0';
	return (str);
}
