/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:19:16 by mathonon          #+#    #+#             */
/*   Updated: 2023/05/02 13:49:13 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_get_envp(char **envp)
{
	int		i;
	char	**split;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == false)
		{
			split = ft_split(&envp[i][5], ':');
			if (split == NULL)
				return (NULL);
			return (split);
		}
	}
	return (NULL);
}

static char	**ft_get_command(int argc, char **argv)
{
	int		i;
	int		j;
	int		n_command;
	char	**dptr;

	n_command = argc - 3;
	dptr = malloc(sizeof(char *) * (n_command + 1));
	if (dptr == NULL)
		return (NULL);
	i = -1;
	j = 1;
	while (++i < n_command && ++j < argc)
	{
		dptr[i] = ft_substr(argv[j], 0, ft_strlen(argv[j]));
		if (dptr[i] == NULL)
		{
			ft_free("%P", dptr);
			return (NULL);
		}
	}
	dptr[i] = NULL;
	return (dptr);
}

int	ft_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	pipex->outfile_fd = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile_fd == -1)
		return (close(pipex->infile_fd), 1);
	pipex->command = ft_get_command(argc, argv);
	if (pipex->command == NULL)
	{
		ft_close("%f, %f", pipex->infile_fd, pipex->outfile_fd);
		return (1);
	}
	pipex->envp_path = ft_get_envp(envp);
	if (pipex->envp_path == NULL)
	{
		ft_free("%P", pipex->command);
		ft_close("%f, %f", pipex->infile_fd, pipex->outfile_fd);
		return (1);
	}
	return (0);
}
