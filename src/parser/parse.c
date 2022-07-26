/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:46:31 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:31 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_loop(t_link *list, t_link **new, char *cmd, char **line)
{
	int		i;

	i = 0;
	while (cmd[i] != '\0')
	{
		while (cmd[i] == ' ' && *line == NULL)
			i++;
		if (cmd[i] == '&' || cmd[i] == ';' || cmd[i] == '\\' \
		|| cmd[i] == '(' || cmd[i] == ')' || cmd[i] == '*')
			invalid_syntax_error(cmd + i);
		if (cmd[i] == '\'' || cmd[i] == '\"')
			i += parse_quotes(cmd + i, line, cmd[i]);
		else if (cmd[i] == '>')
			i += parse_redirects(cmd + i, *new, '>');
		else if (cmd[i] == '<')
			i += parse_redirects(cmd + i, *new, '<');
		else if (cmd[i] == '$' && (ft_isalnum(cmd[i + 1]) || cmd[i + 1] == '?'))
			i += parse_variables (cmd + i, line);
		else if (cmd[i] == '|')
			i += parse_split (cmd + i, line, list, new);
		else if (cmd[i] != '\0')
			*line = ft_my_charjoin(*line, cmd[i++]);
		if (g_data->error == 1 || cmd[i] == '\0')
			return ;
	}
}

void	parse_line(char *cmd, t_link *list)
{
	char	*line;
	t_link	*new;

	new = (t_link *) malloc (sizeof(t_link));
	init_list_element(new);
	line = NULL;
	parse_loop(list, &new, cmd, &line);
	if (line != NULL)
		new->cmd = cmd_split(line);
	free (line);
	tokenizer(list, new);
	if (list->cmd == NULL)
		g_data->error = 1;
}
