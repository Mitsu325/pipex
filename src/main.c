/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:07:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/13 22:12:35 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		fd[2];
	char	**path;

	// TODO: REFATORAÇÃO DA VALIDAÇÃO EM UM NOVO ARQUIVO
	if (argc != 5)
	{
		// TODO: CRIAR CONTROLE DE MENSAGENS DE ERRO
		exit_program(BAD_ARGUMENTS, "Ex: ./pipex file1 cmd1 cmd2 file2")
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
