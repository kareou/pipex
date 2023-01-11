/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:31 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/11 12:15:19 by mkhairou         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	if (s1 && s2)
	{
		i = ft_strlen(a);
		j = ft_strlen(b);
		new = (char *)malloc((i + j + 1));
		if (!new)
			return (0);
		ft_strcpy(new, a);
		ft_strcat(new, b);
		return (new);
	}
	return (0);
}
