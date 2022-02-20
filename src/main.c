/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:31:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (pid == CHILD_PID)
		child_process(argv, envp, fd);
	else
		parent_process(argv, envp, fd);
	waitpid(pid, &status, 0);
	close(fd[0]);
	close(fd[1]);
	return (EX_SUCCESS);
}
