/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:24:27 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/11 11:40:38 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_out_rederect_par(char **av, int fd, int fds)
{
	int	output;

	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (output == -1)
		exit(1);
	dup2(fds, STDIN_FILENO);
	close(fds);
	close(fd);
	dup2(output, 1);
	close(output);
}

void	in_out_rederect_chil(char **av, int fd, int fds)
{
	int	input;

	input = open(av[1], O_RDONLY);
	if (input == -1)
	{
		perror(ft_strjoin("pipex: ", av[1]));
		exit(0);
	}
	dup2(input, STDIN_FILENO);
	close(input);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(fds);
}

void	cmd_execute(char *a, char **cmd, char *const *env)
{
	int	i;

	if (access(a, X_OK) != 0)
		exit_proc(ft_strjoin("pipex: ", cmd[0]), 0);
	i = execve(a, cmd, env);
	if (i == -1)
	{
		free(a);
		exit(126);
	}
}
