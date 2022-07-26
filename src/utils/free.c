/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:46:00 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:00 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_link *list)
{
	t_link	*temp;

	while (list != NULL)
	{
		temp = list->next;
		free(list->file_in);
		free(list->file_out);
		if (list->fdin != 0)
			close (list->fdin);
		if (list->fdout != 0)
			close (list->fdout);
		if (list->cmd != NULL)
			free_split(list->cmd);
		free(list->path);
		free (list);
		list = temp;
	}
}

void	free_all(void)
{
	if (g_data->list != NULL)
		free_list(g_data->list);
	if (g_data->line != NULL)
		free (g_data->line);
	free_split(g_data->env);
	rl_clear_history();
	close(g_data->save_stdin);
	close(g_data->save_stdout);
	free (g_data);
}
