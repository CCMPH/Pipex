/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 08:43:39 by chartema      #+#    #+#                 */
/*   Updated: 2022/06/03 09:22:14 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_error_wrong_cmd(char **cmd)
{
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

int	ft_error(int errno)
{
	perror("Error");
	exit(errno);
}

void	free_paths(char *str, char **strs)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	i = 0;
	if (strs[i] != NULL)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*part_path;
	int		i;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	free_paths(NULL, paths);
	return (0);
}

void	execute_cmd(char *av, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
		ft_error_wrong_cmd(cmd);
	if (execve(path, cmd, envp) == -1)
		ft_error(0);
	free(path);
}
