/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 13:30:31 by chartema      #+#    #+#                 */
/*   Updated: 2022/05/31 15:18:06 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h> // nodig voor open
#include <stdlib.h> //nodig voor malloc
#include <stdio.h> //nodig voor printf en perror
#include <unistd.h> //nodig voor pipe
#include <sys/types.h> //nodig voor waitpid
#include <sys/wait.h> //nodig voor waitpid

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
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
	while (i >= 0)
	{
		free(paths[i]);
		i--;
	}
	free(paths);
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
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		ft_error();
		// Dit is nog niet juiste error
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
}

void	child_process(char **av, char **envp, int *end)
{
	int	fd_input;

	fd_input = open(av[1], O_RDONLY);
	if (fd_input == -1)
		ft_error();
	if (dup2(fd_input, STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	close(end[0]);
	close(fd_input);
	execute_cmd(av[2], envp);
}

void	parent_process(char **av, char **envp, int *end)
{
	int	fd_output;

	fd_output = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_output == -1)
		ft_error();
	if (dup2(end[0], STDIN_FILENO) < 0 || dup2(fd_output, STDOUT_FILENO) < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	close(end[1]);
	close(fd_output);
	execute_cmd(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		end[2];
	pid_t	pid1;

	if (!*envp)
		return (0);
	if (ac == 5)
	{
		if (pipe(end) == -1)
			perror("Pipe: ");
		pid1 = fork();
		if (pid1 == -1)
			perror("Fork: ");
		if (pid1 == 0)
			child_process(av, envp, end);
		waitpid(pid1, NULL, 0);
		parent_process(av, envp, end);
	}
	else
	{
		//ft_putstr_fd("Not correct number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	return (0);
}
