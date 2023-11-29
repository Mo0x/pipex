/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:43:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/29 17:27:15 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

void	pipex(int f1, int f2, char **argv, char **envp);
void	ft_argc_error(char * name);
char	**path_finder(char **envp);
void	ft_exec(int file, char *cmd, char **paths);

#endif
