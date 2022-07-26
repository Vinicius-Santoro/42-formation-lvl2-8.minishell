/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:43:45 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:43:45 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*b;

	a = 0;
	b = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (b == NULL)
		return (NULL);
	while (s[a] != '\0')
	{
		b[a] = f(a, s[a]);
		a++;
	}
	b[a] = '\0';
	return (b);
}
