/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:46:47 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:47 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_from_env(char *var)
{
	int		i;
	int		n;
	char	**str;
	int		size;

	i = -1;
	n = -1;
	str = NULL;
	size = 0;
	if (find_env(var) == NULL)
		return ;
	while (g_data->env[size] != NULL)
		size++;
	str = (char **) malloc (sizeof(char *) * size);
	while (g_data->env[++i] != NULL)
	{
		if (!(ft_strncmp(var, g_data->env[i], ft_strlen(var)) == 0 \
			&& (g_data->env[i][ft_strlen(var)] == '=' \
			|| g_data->env[i][ft_strlen(var)] == '\0')))
			str[++n] = ft_strdup(g_data->env[i]);
	}
	str[n + 1] = NULL;
	free_split (g_data->env);
	g_data->env = str;
}

static int	check_unset_var(char *var)
{
	int	i;

	if (ft_isalpha(var[0]) == 0)
		return (0);
	i = 0;
	while (var[++i] != '\0')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (0);
	}
	return (1);
}

void	unset_built_in(char	**cmd)
{
	int	i;

	i = 0;
	g_data->exit_code = 0;
	if (cmd[1] == NULL)
		return ;
	while (cmd[++i] != NULL)
	{
		if (check_unset_var(cmd[i]))
			remove_from_env(cmd[i]);
		else
		{
			ft_putstr_fd("unset: `", STDERR);
			ft_putstr_fd(cmd[i], STDERR);
			ft_putstr_fd("\': not a valid identifier\n", STDERR);
			g_data->exit_code = 1;
		}
	}
}
