/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:34:58 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:36:03 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The find_exec_path() function find executable path of the 'cmd'. */
/* Return the executable path. NULL if not find. */

#include "pipex.h"

char	*find_exec_path(char *cmd, char **envp)
{
	char	**env_path;
	char	*path;
	char	*exec_path;
	int		i;

	i = 0;
	if (strchr(cmd, '/'))
		return (cmd);
	env_path = find_env_path(envp);
	while (*(env_path + i))
	{
		path = strjoin(*(env_path + i), "/");
		exec_path = strjoin(path, cmd);
		free(path);
		if (access(exec_path, F_OK) == 0)
		{
			free_split(env_path);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	free_split(env_path);
	return (NULL);
}
