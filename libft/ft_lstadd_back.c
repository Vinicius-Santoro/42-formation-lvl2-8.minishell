/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:40:36 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:40:36 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		a = *lst;
		while (a->next != NULL)
			a = a->next;
		a->next = new;
	}
}
