/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:13:52 by mathonon          #+#    #+#             */
/*   Updated: 2023/05/02 13:56:49 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		end_status;

	end_status = 0;
	if (argc == 5)
	{
		if (ft_init(&pipex, argc, argv, envp) == true)
			return (0);
		if (ft_process(&pipex, envp, &end_status) == true)
		{
			ft_close("%f, %f", pipex.infile_fd, pipex.outfile_fd);
			ft_free("%P, %P", pipex.command, pipex.envp_path);
			return (0);
		}
		ft_close("%f, %f", pipex.infile_fd, pipex.outfile_fd);
		ft_free("%P, %P", pipex.command, pipex.envp_path);
	}
	return (end_status);
}
