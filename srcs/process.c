/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:36:06 by mathonon          #+#    #+#             */
/*   Updated: 2023/06/02 11:24:30 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_waitpid(int n_child, int *pid, int *end_status)
{
	int	i;
	int	ret_pid;
	int	child_state;

	i = -1;
	while (++i < n_child)
	{
		ret_pid = waitpid(pid[i], &child_state, 0);
		if (ret_pid > 0)
			*end_status = WEXITSTATUS(child_state);
	}
}

static char	*ft_check_command(char **envp, char *cmd)
{
	char	*dst;
	int		i;

	if (cmd == NULL)
		return (NULL);
	i = -1;
	while (envp[++i] != NULL)
	{
		dst = ft_join(3, envp[i], "/", cmd);
		if (dst == NULL)
			return (NULL);
		if (access(dst, X_OK) == false)
			return (dst);
		dst = NULL;
		free(dst);
	}
	return (NULL);
}

static void	ft_second_child(t_pipex *pipex, char **envp, int *filedes)
{
	char	*cmd;
	char	**cmd_args;

	close(filedes[1]);
	dup2(filedes[0], STDIN_FILENO);
	close(filedes[0]);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->outfile_fd);
	cmd_args = ft_split(pipex->command[1], ' ');
	if (cmd_args == NULL)
		exit(1);
	cmd = ft_check_command(pipex->envp_path, cmd_args[0]);
	if (cmd == NULL)
		ft_cmd_error(pipex->command[1], cmd_args[0]);
	if (execve(cmd, cmd_args, envp) == -1)
	{
		perror(cmd_args[0]);
		exit(1);
	}
}

static void	ft_first_child(t_pipex *pipex, char **envp, int *filedes)
{
	char	*cmd;
	char	**cmd_args;

	close(filedes[0]);
	dup2(pipex->infile_fd, STDIN_FILENO);
	close(pipex->infile_fd);
	dup2(filedes[1], STDOUT_FILENO);
	close(filedes[1]);
	cmd_args = ft_split(pipex->command[0], ' ');
	if (cmd_args == NULL)
		exit(1);
	cmd = ft_check_command(pipex->envp_path, cmd_args[0]);
	if (cmd == NULL)
		ft_cmd_error(pipex->command[0], cmd_args[0]);
	if (execve(cmd, cmd_args, envp) == -1)
	{
		perror(cmd_args[0]);
		exit(1);
	}
}

int	ft_process(t_pipex *pipex, char **envp, int *end_status)
{
	int		i;
	int		pid[2];
	int		filedes[2];
	void	(*childs[2])(t_pipex *, char **, int *);

	childs[0] = &ft_first_child;
	childs[1] = &ft_second_child;
	if (pipe(filedes) == -1)
		return (1);
	i = -1;
	while (++i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit (1);
		else if (pid[i] == false)
			childs[i](pipex, envp, filedes);
	}
	ft_close("%F", filedes);
	ft_waitpid(2, pid, end_status);
	return (0);
}
