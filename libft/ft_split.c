/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:42:44 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:42:44 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_count(char *s, char c)
{
	int	count;
	int	n;

	n = 0;
	count = 0;
	while (s[n] != '\0')
	{
		if (s[n] != c && (s[n + 1] == c || s[n + 1] == '\0'))
			count++;
		n++;
	}
	return (count);
}

static void	my_string(char	*s, char c, char **matriz)
{
	int	n;
	int	start;
	int	strcount;

	n = 0;
	start = 0;
	strcount = 0;
	while (s[n] != '\0')
	{
		while (s[n] == c)
			n++;
		start = n;
		while (s[n] != c && s[n] != '\0')
			n++;
		if ((s[n] == c || s[n] == '\0') && s[n - 1] != c)
		{
			matriz[strcount] = ft_substr(s, start, n - start);
			strcount++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	int		count;

	count = my_count((char *)s, c);
	matriz = (char **) malloc (sizeof(char *) * (count + 1));
	if (matriz == NULL)
		return (NULL);
	my_string((char *) s, c, matriz);
	matriz[count] = NULL;
	return (matriz);
}
