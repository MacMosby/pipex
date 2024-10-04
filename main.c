/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodenbusch <marcrodenbusch@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:31:57 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/10/05 00:45:28 by marcrodenbu      ###   ########.fr       */
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
		i++;
	}
}

void	init_data(t_data *data, int argc)
{
	data->num_of_processes = argc - 3;
	init_pipes(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data, argc);
	executor(&data);
	wait_loop(&data);
	return (0);
}
