/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:31 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/11 16:44:16 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *a, char *b)
{
	int	i;
	int	j;

	i = ft_strlen(a);
	j = 0;
	while (b[j] != '\0')
	{
		a[i + j] = b[j];
		j++;
	}
	a[i + j] = '\0';
	return (a);
}

char	*ft_strcpy(char *a, char *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		new = (char *)malloc((i + j + 1));
		if (!new)
			return (0);
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
		return (new);
	}
	return (0);
}
