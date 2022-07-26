/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:46:10 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:10 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenizer(t_link *list, t_link *new)
{
	if (list->cmd == NULL)
	{
		list->append = new->append;
		list->delimiter = new->delimiter;
		list->file_in = new->file_in;
		list->file_out = new->file_out;
		list->cmd = new->cmd;
		list->next = NULL;
		list->fdin = new->fdin;
		list->fdout = new->fdout;
		list->path = new->path;
		free (new);
	}
	else
	{
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}

void	init_list_element(t_link *new)
{
	new->cmd = NULL;
	new->file_in = NULL;
	new->file_out = NULL;
	new->next = NULL;
	new->delimiter = 0;
	new->append = 0;
	new->fdin = 0;
	new->fdout = 0;
	new->path = NULL;
}
