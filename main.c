/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodenbusch <marcrodenbusch@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:31:57 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/10/05 19:57:22 by marcrodenbu      ###   ########.fr       */
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
		set_redirections(data, i);
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

void	wait_loop(t_data *data)
{
	int	i = 0;
	int	status = 0;

	while (i < data->num_of_processes)
	{
		waitpid(data->pids[i], &status, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_data(&data, argc, argv, envp);
	executor(&data);
	wait_loop(&data);
	return (0);
}
