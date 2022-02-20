/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:36:47 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:37:36 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The find_env_path() function find the directories stored in the PATH 
environment variable. */
/* Return the array of directories.*/

#include "pipex.h"

char	**find_env_path(char **envp)
{
	int	i;

	i = 0;
	while (strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	return (split(envp[i] + 5, ':'));
}
