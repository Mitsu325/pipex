/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/17 20:21:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ! Teve atualização do pdf: Não pode usar libft
// TODO: Refatoração do libft

/* The find_exec_path() function find executable path of the 'cmd'. */
/* Return the executable path. NULL if not find. */
char	*find_exec_path(char *cmd, char **env_path)
{
	char	*path;
	char	*exec_path;
	int		i;

	i = 0;
	while (*(env_path + i))
	{
		path = ft_strjoin(*(env_path + i), "/");
		exec_path = ft_strjoin(path, cmd);
		free(path);
		if (access(exec_path, F_OK) == 0)
			return (exec_path);
		i++;
	}
	return (NULL);
}

/* The run_cmd() function execute command. */
void	run_cmd(char *argv_cmd, char **envp, char **env_path)
{
	char	**cmd;
	char	*exec_path;

	cmd = ft_split(argv_cmd, ' ');
	exec_path = find_exec_path(cmd[0], env_path);
	if (execve(exec_path, cmd, envp) == -1)
		perror("Ups");
}

/* The child_process() function modify the stdin and stdout. Execute the cmd
and the result will be used in the parent process.*/
void	child_process(char **argv, char **envp, int *fd,  char **env_path)
{
	int	fd_input_file;

	fd_input_file = open(argv[1], O_RDONLY, MODE_RW);
	dup2(fd_input_file, STDIN);
	dup2(fd[1], STDOUT);
	close(fd[0]);
	run_cmd(argv[2], envp, env_path);
}

/* The parent_process() function modify the stdin and stdout. Execute the cmd
with the result of the child process as input value.*/
void	parent_process(char **argv, char **envp, int *fd,  char **env_path)
{
	int	fd_output_file;

	fd_output_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, MODE_RW);
	if (fd_output_file == -1)
		error_safe_exit(env_path);
	dup2(fd[0], STDIN);
	dup2(fd_output_file, STDOUT);
	close(fd[1]);
	run_cmd(argv[3], envp, env_path);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		fd[2];
	char	**env_path;
	int		status;

	if (argc != 5)
		error_message("Wrong arguments",
		"./pipex input_file cmd1 cmd2 output_file");
	env_path = find_env_path(envp);
	if (pipe(fd) == -1)
		error_safe_exit(env_path);
	pid = fork();
	if (pid == -1)
		error_safe_exit(env_path);
	if (pid == 0)
		child_process(argv, envp, fd, env_path);
	waitpid(pid, &status, 0);
	parent_process(argv, envp, fd, env_path);
	close(fd[0]);
	close(fd[1]);
	free_split(env_path);
	return (EXIT_SUCCESS);
}
