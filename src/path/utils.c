/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:55:58 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 20:12:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* The find_env_path() function find the directories stored in the PATH 
environment variable.
*/
/* Return the array of directories.*/
char	**find_env_path(char **envp)
{
	int	i;

	i = 0;
	while (strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	return (split(envp[i] + 5, ':'));
}

/* The free_split() function dynamically de-allocate the memory from a table.*/
void	free_split(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (*(table + i))
		free(*(table + i++));
	free(table);
}
