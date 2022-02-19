/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:34:58 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 15:35:21 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* The find_exec_path() function find executable path of the 'cmd'. */
/* Return the executable path. NULL if not find. */
char	*find_exec_path(char *cmd, char **envp)
{
	char	**env_path;
	char	*path;
	char	*exec_path;
	int		i;

	i = 0;
	env_path = find_env_path(envp);
	while (*(env_path + i))
	{
		path = ft_strjoin(*(env_path + i), "/");
		exec_path = ft_strjoin(path, cmd);
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
