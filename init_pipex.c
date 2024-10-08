/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:16:19 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/10/08 16:16:20 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipes(t_data *data)
{
	int	i;

	data->pipes = ft_calloc(data->num_of_processes - 1, sizeof(int *));
	if (!data->pipes)
	{
		// EXIT HANDLE
		exit (1);
	}
	i = 0;
	while (i < data->num_of_processes - 1)
	{
		data->pipes[i] = ft_calloc(2, sizeof(int));
		if (!data->pipes[i])
		{
			// EXIT HANDLE
			exit (1);
		}
		if (pipe(data->pipes[i]) == -1)
		{
			// EXIT HANDLE
			exit (1);
		}
		i++;
	}
}

void	init_pids(t_data *data)
{
	data->pids = ft_calloc(data->num_of_processes, sizeof(int));
	if (!data->pids)
	{
		// EXIT HANDLE
		exit (1);
	}
}

void	init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->ac = argc;
	data->av = argv;
	data->env = envp;
	data->num_of_processes = argc - 3;
	init_pipes(data);
	init_pids(data);
}
