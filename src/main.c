/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/16 00:51:38 by pmitsuko         ###   ########.fr       */
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
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	return (ft_split(envp[i] + 5, ':'));
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

/* The error_safe_exit() function print error message to the stderr and exit
the process safely.
*/
void	error_safe_exit(char **env_path)
{
	free_split(env_path);
	perror("Error");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	// int		pid;
	int		fd[2];
	char	**env_path;

	if (argc != 5)
		error_message("Wrong arguments", "./pipex file1 cmd1 cmd2 file2");
	env_path = find_env_path(envp);
	if (pipe(fd) == -1)
		error_safe_exit(env_path);
	ft_putstr_fd(env_path[1], STDOUT);
	ft_putstr_fd("\n", STDOUT);
	ft_putstr_fd(argv[0], STDOUT);
	ft_putstr_fd("\n", STDOUT);
	return (EXIT_SUCCESS);
}
