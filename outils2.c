/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:47:15 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/12 15:05:59 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_sep(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == 34 || a[i] == 39)
			return (i);
		i++;
	}
	return (0);
}

int	tet(char *a)
{
	int	i;

	i = find_sep(a);
	if (a[i] == 34 && a[i + 1] == 39)
		return (0);
	if (a[i] == 34 && a[i + 1] != 39)
		return (2);
	else
		return (1);
}

char	**command_check(char *av)
{
	char	**cmd;

	if (ft_strchr(av, 39) || ft_strchr(av, 34))
	{
		if (tet(av) == 0)
			cmd = ft_split(av, 34);
		else if (tet(av) == 2)
			cmd = ft_split(av, 34);
		else
		{
			cmd = ft_split(av, 39);
			if (ft_strchr(cmd[1], 39))
				cmd[1] = copy(cmd[1]);
		}
	}
	else
		cmd = ft_split(av, ' ');
	return (cmd);
}

char	*exit_proc(char *a, int i)
{
	char	*s;

	if (i == 1)
	{
		perror(a);
		free(a);
		exit(0);
	}
	else
	{
		s = ft_strjoin(a, ": command not found\n");
		write(2, s, ft_strlen(s));
		free(a);
		free(s);
		exit(127);
	}
}

char	*handel(char *a)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(ft_strlen(a));
	while (a[i])
	{
		if (a[i] == ' ')
			break ;
		s[i] = a[i];
		i++;
	}
	s[i] = '\0';
	free(a);
	return (s);
}
