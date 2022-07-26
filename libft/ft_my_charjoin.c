/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_charjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:42:04 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:42:04 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_charjoin(char *s1, char s2)
{
	char	*s;
	int		count;

	count = -1;
	if (s2 == '\0')
		return (s1);
	if (s1 == NULL)
	{
		s = malloc (2 * sizeof(char));
		s[0] = s2;
		s[1] = '\0';
	}
	else
	{
		s = malloc ((ft_strlen(s1) + 2) * sizeof(char));
		if (s == NULL)
			return (NULL);
		while (s1[++count] != '\0')
			s[count] = s1[count];
		s[count++] = s2;
		s[count] = '\0';
	}
	free (s1);
	return (s);
}
