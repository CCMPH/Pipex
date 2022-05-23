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

int	pipex(t_list *data)
{
	int	exit_code;
	int	*pipefd;

	exit_code = 0;
	printf("kom ik hier2?\n");
	pipefd = malloc((2 * (data->size - 1)) * sizeof(int));
	if (!pipefd)
		//ERROR
	if (pipe(pipefd + 2) < 0)
		//ERROR
	printf("kom ik hier?\n");
	return (exit_code);
}

int	main(int ac, char **av, char **envp)
{
	t_list	data;
	int		exit_code;

	printf("kom ik hier?\n");
	data.input_fd = open(av[1], O_RDONLY);
	data.output_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data.input_fd < 0 || data.output_fd < 0 || ac != 5)
		// moet er een error tekst als input anders is dan 5?
		printf("kom ik hier58?\n");
		// hij klapt er hier uit, maar waarom??
		return (1);
	data.envp = envp;
	data.av = av;
	data.size = ac - 3;
	printf("kom ik hier?\n");
	exit_code = pipex(&data);
	return (exit_code);
}

// https://www.youtube.com/watch?v=6xbLgZpOBi8
// https://github.com/gabcollet/pipex/blob/master/srcs/pipex.c
// https://github.com/mcombeau/pipex
// https://www.codequoi.com/en/pipex-reproducing-the-pipe-operator-in-c/
// https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901