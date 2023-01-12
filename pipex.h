/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:09:46 by mkhairou          #+#    #+#             */
/*   Updated: 2023/01/12 14:41:18 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEF "\033[0m"
# define RED "\033[0;31m"

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*check_path(char *cmd, char *const *env, int i);
char	*copy(char *a);
char	*handel(char *a);
int		tet(char *a);
char	**command_check(char *av);
char	*exit_proc(char *a, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	in_out_rederect_par(char **av, int fd, int fds);
void	in_out_rederect_chil(char **av, int fd, int fds);
void	cmd_execute(char *a, char **cmd, char *const *env);
void	free_array(char **a, int i, int stop);
int		c_count(const char *s, const char c);

#endif