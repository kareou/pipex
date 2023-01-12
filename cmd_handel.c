/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:24:27 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/12 16:24:34 by mkhairou         ###   ########.fr       */
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
	int		input;
	char	*a;

	input = open(av[1], O_RDONLY);
	if (input == -1)
	{
		a = ft_strjoin("pipex: ", av[1]);
		perror(a);
		free(a);
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
	{
		free_array(cmd,1,array_len(cmd));
		exit_proc(cmd[0], 0);
	}
	i = execve(a, cmd, env);
	if (i == -1)
	{
		free(a);
		free_array(cmd, 0, array_len(cmd));
		exit(126);
	}
}

int	array_len(char **a)
{
	int	i;

	while (a[i])
		i++;
	return (i);
}
