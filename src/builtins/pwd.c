/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:46:35 by vnazioze          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:35 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_built_in(void)
{
	char	*str;

	g_data->exit_code = 0;
	str = malloc (1024);
	ft_putstr_fd(getcwd(str, 1024), STDOUT);
	write (1, "\n", 1);
	free (str);
	return ;
}
