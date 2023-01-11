/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:33:36 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/11 13:30:42 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while ((a[i] != '\0' && b[i] != '\0') && n > i)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (i < n)
		return (a[i] - b[i]);
	return (0);
}

char	*find_paths(char *const *env)
{
	int		i;
	char	*paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_strchr(env[i], '/');
			return (paths);
		}
		i++;
	}
	paths = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki";
	return (paths);
}

char	*check_path(char *cmd, char *const *env)
{
	int		i;
	char	*ev;
	char	**a;
	char	*tmp;

	i = -1;
	ev = find_paths(env);
	if (ev == NULL)
		exit_proc(ft_strjoin("pipex: ", cmd), 0);
	a = ft_split(ev, ':');
	while (a[++i])
	{
		a[i] = ft_strjoin(a[i], "/");
		tmp = ft_strjoin(a[i], cmd);
		free(a[i]);
		if (access(tmp, F_OK) == 0)
		{
			free_array(a, i + 1, c_count(ev,':'));
			return (tmp);
		}
		free(tmp);
	}
	free(a);
	return (NULL);
}

char	*copy(char *a)
{
	int		i;
	int		j;
	char	*re;

	i = 0;
	j = 0;
	re = malloc(ft_strlen(a));
	while (i < (int)ft_strlen(a))
	{
		if (a[i] != 34)
		{
			re[j] = a[i];
			j++;
		}
		i++;
	}
	re[j] = '\0';
	free(a);
	return (re);
}
