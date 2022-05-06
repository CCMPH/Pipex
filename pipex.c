/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 13:30:31 by chartema      #+#    #+#                 */
/*   Updated: 2022/05/06 14:37:19 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // nodig voor open

int	pipex(int input_file, int output_file, char **av, char **envp)
{

}

int	main(int ac, char **av, char **envp)
{
	int	input_file;
	int	output_file;

	input_file = open(av[1], O_RDONLY);
	output_file = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (input_file < 0 || output_file < 0 || ac != 5)
		// moet er een error tekst als input anders is dan 5?
		return ();
	pipex(input_file, output_file, av, envp);
	return (0);
}


// https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901