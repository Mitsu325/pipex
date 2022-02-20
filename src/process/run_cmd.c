/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:33:36 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:41:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The run_cmd() function execute command. */

#include "pipex.h"

int	run_cmd(char *argv_cmd, char **envp, int pid)
{
	char	**cmd;
	char	*exec_path;

	cmd = split(argv_cmd, ' ');
	exec_path = find_exec_path(cmd[0], envp);
	if (!exec_path)
		cmd_not_found(cmd, pid);
	else if (execve(exec_path, cmd, envp) == -1)
	{
		free_split(cmd);
		free(exec_path);
		perror("Error");
	}
	return (EX_FAILURE);
}
