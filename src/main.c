/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:46:15 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:15 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*g_data;

void	do_command(char *line, char **env)
{
	t_link	*list;

	signal (SIGQUIT, quit_core);
	g_data->in_exec = 1;
	if (line[0] == '\0')
		return ;
	add_history(line);
	list = (t_link *) malloc (sizeof (t_link));
	g_data->list = list;
	list->cmd = NULL;
	parse_line(line, list);
	if (g_data->error == 1)
	{
		free_list(g_data->list);
		return ;
	}
	while (list != NULL)
	{
		if (list->cmd != NULL)
			exec_command(list, env);
		list = list->next;
	}
	free_list(g_data->list);
}

void	readline_loop(char **env)
{
	signal (SIGINT, kill_loop);
	while (1)
	{
		signal (SIGQUIT, SIG_IGN);
		g_data->error = 0;
		g_data->in_exec = 0;
		g_data->line = NULL;
		g_data->list = NULL;
		g_data->here_doc = 0;
		g_data->line = readline("$ ");
		if (g_data->line != NULL)
			do_command(g_data->line, env);
		else
		{
			free_all();
			write (1, "exit\n", 5);
			exit (0);
		}
		free (g_data->line);
		if (g_data->exit == 1)
			exit (0);
		dup2(g_data->save_stdin, STDIN);
		dup2(g_data->save_stdout, STDOUT);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
	{
		perror("Invalid arguments\n");
		exit (1);
	}
	g_data = (t_data *) malloc (sizeof(t_data));
	g_data->exit_code = 0;
	g_data->exit = 0;
	g_data->exec_pid = 0;
	g_data->env = copy_first_env(env);
	g_data->save_stdin = dup(STDIN);
	g_data->save_stdout = dup(STDOUT);
	readline_loop(env);
}
