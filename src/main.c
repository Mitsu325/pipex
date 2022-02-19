/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 13:45:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ! Teve atualização do pdf: Não pode usar libft
// TODO: Refatoração do libft

void	error_exit()
{
	perror("Error");
	exit(EXIT_FAILURE);
}

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

// Criar todas as possibilidades de caminho e tentar execve
char	*create_exec_path(char *env_path, char *cmd)
{
	char	*exec_path;
	int		i;

	if (!env_path || !cmd)
		return (NULL);
	exec_path = (char *)malloc((ft_strlen(env_path) + ft_strlen(cmd) + 2) * sizeof(char));
	if (!exec_path)
		return(NULL);
	while (*env_path)
		exec_path[i++] = *env_path++;
	*(exec_path + i) = '/';
	while (*cmd)
		exec_path[i++] = *cmd++;
	*(exec_path + i) = '\0';
	return (exec_path);
}

int	check_cmd(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (EXIT_FAILURE);
		cmd++;
	}
	return (EXIT_SUCCESS);
}

/* The run_cmd() function execute command. */
int	run_cmd_child(char *argv_cmd, char **envp)
{
	char	**cmd;
	char	*exec_path;

	cmd = ft_split(argv_cmd, ' ');
	exec_path = find_exec_path(cmd[0], envp);
    // ft_putstr_fd("Path: ", STDOUT);
	// ft_putstr_fd(exec_path, STDOUT);
	// ft_putstr_fd("\n", STDOUT); 
	if (execve(exec_path, cmd, envp) == -1)
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
	// char	**env_path;
	char	*exec_path;
	// int		i;

	cmd = ft_split(argv_cmd, ' ');
	exec_path = find_exec_path(cmd[0], envp);
	// ft_putstr_fd("Path: [", STDOUT);
	// ft_putstr_fd(exec_path, STDOUT);
	// ft_putstr_fd("]\n", STDOUT);
	if (execve(exec_path, cmd, envp) == -1)
    {
        free_split(cmd);
        free(exec_path);
		perror("Error parent");
    }
	// env_path = find_env_path(envp);
	// i = 0;
	// while (env_path[i])
	// {
	// 	exec_path = create_exec_path(env_path[i], cmd[0]);
	// 	execve(exec_path, cmd, envp);
	// 	free(exec_path);
	// 	i++;
	// }
	// free_split(cmd);
	// perror("Error parent");
    return (EXIT_FAILURE);
}

/* The child_process() function modify the stdin and stdout. Execute the cmd
and the result will be used in the parent process.*/
void	child_process(char **argv, char **envp, int *fd)
{
	int	fd_input_file;

	fd_input_file = open(argv[1], O_RDONLY, MODE_RWE);
	dup2(fd_input_file, STDIN);
	dup2(fd[1], STDOUT);
	close(fd[0]);
	close(fd[1]);
	run_cmd_child(argv[2], envp);
}

/* The parent_process() function modify the stdin and stdout. Execute the cmd
with the result of the child process as input value.*/
void	parent_process(char **argv, char **envp, int *fd)
{
	int	fd_output_file;
    int run_cmd_status;

	fd_output_file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, MODE_RWE);
	if (fd_output_file == -1)
		error_exit();
	dup2(fd[0], STDIN);
	dup2(fd_output_file, STDOUT);
	close(fd[0]);
	close(fd[1]);
	run_cmd_status = run_cmd_parent(argv[3], envp);
    if (run_cmd_status)
	{
		write(1, "", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (argc != 5)
		error_message("Wrong arguments",
		"./pipex input_file cmd1 cmd2 output_file");
	if (pipe(fd) == -1)
		error_exit();
	pid = fork();
	if (pid == -1)
		error_exit();
	if (pid == 0)
		child_process(argv, envp, fd);
	else
		parent_process(argv, envp, fd);
	waitpid(pid, &status, 0);
	close(fd[0]);
	close(fd[1]);
	return (EXIT_SUCCESS);
}
