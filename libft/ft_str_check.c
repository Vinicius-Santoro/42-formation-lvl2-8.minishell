/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:42:48 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:42:48 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_check(const char *s1, const char *s2)
{
	int	a;

	a = 0;
	while (s1[a] == s2[a] && s1[a] != '\0')
		a++;
	if (s1[a] == '\n' && s2[a] == '\0')
		return (1);
	else if (s1[a] == s2[a])
		return (1);
	else
		return (0);
}
