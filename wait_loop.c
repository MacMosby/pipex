/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:19:09 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/10/08 16:19:10 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
