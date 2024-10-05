/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodenbusch <marcrodenbusch@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:33:50 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/10/05 19:49:13 by marcrodenbu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_data
{
	int	ac;
	char **av;
	char **env;
	int	num_of_processes;
	int	**pipes;
	int **pids;
}	t_data;

#endif
