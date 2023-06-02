/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:49:48 by mathonon          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:36 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../lib/libft/libft.h"

# define CNF "command not found: "
# define PMD "permission denied: "

typedef struct s_pipex {
	int		infile_fd;
	int		outfile_fd;
	char	**command;
	char	**envp_path;
}				t_pipex;

enum e_boolean {
	false,
	true,
};

int		ft_init(t_pipex *pipex, int argc, char **argv, char **envp);
int		ft_process(t_pipex *pipex, char **envp, int *end_status);
void	ft_cmd_error(char *args, char *cmd);
int		ft_free(const char *formats, ...);
int		ft_close(const char *formats, ...);
char	*ft_join(int argc, ...);

#endif
