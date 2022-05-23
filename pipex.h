/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 13:30:49 by chartema      #+#    #+#                 */
/*   Updated: 2022/05/23 14:57:18 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_list
{
	int		input_fd;
	int		output_fd;
	int		size;
	char	**envp;
	char	**av;
}	t_list;

#endif