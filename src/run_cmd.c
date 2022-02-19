/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:33:36 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 19:32:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char **cmd)
{
	putstr_fd(cmd[0], STDERR);
	free_split(cmd);
	putstr_fd(": ", STDERR);
	putstr_fd("command not found", 2);
	putstr_fd("\n", 2);
}

/* The run_cmd() function execute command. */
int	run_cmd_child(char *argv_cmd, char **envp)
{
	char	**cmd;
	char	*exec_path;

	cmd = split(argv_cmd, ' ');
	exec_path = find_exec_path(cmd[0], envp);
	if (!exec_path)
		cmd_not_found(cmd);
	else if (execve(exec_path, cmd, envp) == -1)
	{
		free_split(cmd);
		free(exec_path);
		perror("Error child");
	}
	return (EXIT_FAILURE);
}

/* The run_cmd() function execute command. */
int	run_cmd_parent(char *argv_cmd, char **envp)
{
	char	**cmd;
	char	*exec_path;

	cmd = split(argv_cmd, ' ');
	exec_path = find_exec_path(cmd[0], envp);
	if (!exec_path)
	{
		cmd_not_found(cmd);
		exit(DEL);
	}
	if (execve(exec_path, cmd, envp) == -1)
	{
		free_split(cmd);
		free(exec_path);
		perror("Error parent");
	}
	return (EXIT_FAILURE);
}
