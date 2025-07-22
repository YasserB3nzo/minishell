/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:56:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/19 13:56:48 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"
#include <unistd.h>
#include <stdlib.h>

extern int g_exit_status;

void	pwd(char **args)
{

	char	*cwd;

	if (args[1])
	{
		ft_putstr_fd("minishell: pwd: too many arguments\n", STDERR_FILENO);
		g_exit_status = 1;
		return;
	}

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		ft_putstr_fd(cwd, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(cwd);
		g_exit_status = 0;
	}
	else
	{
		ft_putstr_fd("minishell: pwd: error retrieving current directory\n", STDERR_FILENO);
		g_exit_status = 1;
	}
}
