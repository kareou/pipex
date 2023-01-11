/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:11:29 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/11 13:34:15 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childe(char **av, char *const *env, int fd, int fds)
{
	char	**cmd;
	char	*a;
	int i = 1;

	in_out_rederect_chil(av, fd, fds);
	if (av[2][0] == 47 || (av[2][0] == '.' && av[2][1] == 47) || access(av[2],
			F_OK | X_OK) == 0)
	{
		if (access(av[2], F_OK | X_OK) != 0)
			exit_proc(ft_strjoin("pipex :", av[2]), 1);
		else
		{
			cmd = command_check(av[2]);
			cmd[0] = handel(cmd[0]);
			a = cmd[0];
		}
	}
	else
	{
		cmd = command_check(av[2]);
		cmd[0] = handel(cmd[0]);
		a = check_path(cmd[0], env);
	}
	// while(1)
	// {
	// 	i++;
	// }
	cmd_execute(a, cmd, env);
	cmd_execute(a, cmd, env);
}

void	parrent(char **av, char *const *env, int fd, int fds)
{
	char	**cmd;
	char	*a;
	int i = 1;

	in_out_rederect_par(av, fd, fds);
	if (av[3][0] == 47 || (av[3][0] == '.' && av[3][1] == 47))
	{
		if (access(av[3], F_OK | X_OK) != 0)
		{
			perror(ft_strjoin("pipex :", av[3]));
			exit(0);
		}
		else
		{
			cmd = command_check(av[3]);
			cmd[0] = handel(cmd[0]);
			a = cmd[0];
		}
	}
	else
	{
		cmd = command_check(av[3]);
		cmd[0] = handel(cmd[0]);
		a = check_path(cmd[0], env);
	}
	// while(1)
	// {
	// 	i++;
	// }
	cmd_execute(a, cmd, env);
}

void	start(char **av, char *const *env)
{
	int	fd[2];
	int	id;
	int	p;

	p = pipe(fd);
	if (p == -1)
		return (perror(RED "ERROR: " DEF));
	id = fork();
	if (id == -1)
	{
		perror("ERROR: ");
		exit(1);
	}
	if (id == 0)
		childe(av, env, fd[1], fd[0]);
	else
		parrent(av, env, fd[1], fd[0]);
}

int	main(int ac, char **av, char *const *env)
{
	if (ac < 5)
	{
		perror(RED "ERROR: " DEF);
		exit(1);
	}
	if (ac == 5)
	{
		start(av, env);
	}
	return (0);
}
