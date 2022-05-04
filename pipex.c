/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 13:30:31 by chartema      #+#    #+#                 */
/*   Updated: 2022/05/04 13:43:45 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // nodig voor open

int	main(int ac, char **av, char **envp)
{
	int	input_file;
	int	output_file;

	input_file = open(av[1], O_RDONLY);
	output_file = open(av[4], O_CREAT | O_RDWR | O_TRUNC);
	if (f1 < 0 || f2 < 0)
		return (-1);
}
