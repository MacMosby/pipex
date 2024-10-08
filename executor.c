/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:17:53 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/10/08 16:17:54 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_executor(t_data *data, int i)
{
	char *path;
	char **args;

	data->pids[i] = fork();
	if (!data->pids[i])
	{
		// EXIT HANDLE
		exit (1);
	}
	if (data->pids[i] == 0)
	{
		close_pipes(data);
		path = get_path(data->av[i + 2]);
		if (execve(path, args, data->env) == -1)
		{
			// EXIT HANDLE
			exit (1);
		}
	}
}

void	executor(t_data *data)
{
	int	i = 0;

	while (i < data->num_of_processes)
	{
		fork_executor(data, i);
		i++;
	}
}
