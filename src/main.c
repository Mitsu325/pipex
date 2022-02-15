/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/15 02:54:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_env_path(char **envp)
{
	char	**env_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	env_path = ft_split(envp[i] + 5, ':');
	return (env_path);
}

int	main(int argc, char **argv, char **envp)
{
	// int		pid;
	// int		fd[2];
	char	**env_path; // ! norminette: Variable declaration not at start of function

	if (argc != 5)
		error_handler("Bad arguments", "Ex: ./pipex file1 cmd1 cmd2 file2");
	env_path = find_env_path(envp);
	ft_putstr_fd(env_path[1], STDOUT);
	ft_putstr_fd("\n", STDOUT);
	ft_putstr_fd(argv[0], STDOUT);
	ft_putstr_fd("\n", STDOUT);
	return (EXIT_SUCCESS);
}
