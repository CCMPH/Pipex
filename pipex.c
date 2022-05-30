/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 13:30:31 by chartema      #+#    #+#                 */
/*   Updated: 2022/05/23 15:27:40 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h> // nodig voor open
#include <stdlib.h> //nodig voor malloc
#include <stdio.h> //nodig voor printf
#include <unistd.h> //nodig voor pipe

void	child_process(char **av, char **envp, int *pipe_end)
{
	int	fd_input;

	fd_input = open(av[1], O_RDONLY);
	if (fd_input == -1)
		//ERROR
	if (dup2(fd_input, STDIN_FILENO) < 0 || dup2(pipe_end[1], STDOUT_FILENO) < 0)
		//ERROR
	close(pipe_end[0]);
	close(fd_input); // is dit nodig of overbodig?
	execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *pipe_end)
{
	int	fd_output;

	fd_output = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	// soorten opzoeken en opschrijven
	if (fd_output == -1)
		//ERROR
	if (dup2(pipe_end[0], STDIN_FILENO) < 0 || dup2(fd_output, STDOUT_FILENO) < 0)
		//ERROR
	close(pipe_end[1]);
	close(fd_output); // is dit nodig of overbodig?
	execute(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pipe_end[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			//ERROR
		pid1 = fork();
		if (pid1 == -1)
			//ERROR
		if (pid1 == 0)
			child_process(av, envp, pipe_end);
		waitpid(pid1, NULL, 0);
		parent_process(av, envp, pipe_end);
	}
	else
		// ERROR MANAGEMENT
	return (0);
}

// https://www.youtube.com/watch?v=6xbLgZpOBi8
// https://github.com/gabcollet/pipex/blob/master/srcs/pipex.c
// https://github.com/gabcollet/pipex/tree/master/srcs
// https://github.com/mcombeau/pipex
// https://www.codequoi.com/en/pipex-reproducing-the-pipe-operator-in-c/
// https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901