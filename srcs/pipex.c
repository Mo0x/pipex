/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:24 by mgovinda          #+#    #+#             */
/*   Updated: 2023/11/29 17:44:44 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_array(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	**path_finder(char **envp)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	paths = NULL;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	if (envp[i])
	{
		envp[i] = envp[i] + 5;
		paths = ft_split(envp[i], ':');
		i = 0;
		while (paths[i])
		{
			tmp = ft_strjoin(paths[i], "/");
			if (!tmp)
			{
				ft_free_array((void **)paths);
				return (NULL);
			}	
			free(paths[i]);
			paths[i] = tmp;
			i++;
		}
	}
	return (paths);
}

char	*command_finder(char **paths, char *cmd)
{

}

int process_one(int f1, char *cmd)
{
	//haha	
}

void 	exec(int file, char *cmd, char **envp)
{
	//char	**	
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		super_pipe[2];
	int		status;
	pid_t	child_1;
	pid_t	child_2;
	char	**paths;

	paths = path_finder(envp);
	pipe(super_pipe);
	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork error: "));
	if (child_1 == 0)
		process_one(f1, argv[2]);
	child_2 = fork();
	if (child_2 < 0)
		return (perror("Fork error: "));
	if (child_2 == 0)
		process_two(f2, argv[3]);
	close(super_pipe[0]);
	close(super_pipe[1]);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
}
