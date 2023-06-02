/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <mathonon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:26:45 by mathonon          #+#    #+#             */
/*   Updated: 2023/05/02 13:32:06 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_free(const char *formats, ...)
{
	va_list	ap;
	int		i;
	void	**dptr;

	va_start(ap, formats);
	while (*formats != '\0')
	{
		if (*formats == '%')
		{
			++formats;
			if (*formats == 'p')
				free(va_arg(ap, void *));
			else if (*formats == 'P')
			{
				dptr = va_arg(ap, void **);
				i = 0;
				while (dptr[i] != NULL)
					free(dptr[i++]);
				free(dptr);
			}
		}
		++formats;
	}
	va_end(ap);
	return (0);
}

int	ft_close(const char *formats, ...)
{
	va_list			ap;
	int				*fd;
	unsigned long	i;

	va_start(ap, formats);
	while (*formats != '\0')
	{
		if (*formats == '%')
		{
			++formats;
			if (*formats == 'f')
				close(va_arg(ap, int));
			else if (*formats == 'F')
			{
				fd = va_arg(ap, int *);
				i = 0;
				while (i < sizeof(fd) / 4)
					close(fd[i++]);
			}
		}
		++formats;
	}
	va_end(ap);
	return (0);
}

static int	ft_get_len(int argc, va_list aq)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (++i < argc)
		len += ft_strlen(va_arg(aq, char *));
	va_end(aq);
	return (len);
}

char	*ft_join(int argc, ...)
{
	va_list	ap;
	va_list	aq;
	char	*tmp;
	char	*dst;
	int		len;

	va_start(ap, argc);
	va_copy(aq, ap);
	len = ft_get_len(argc, aq);
	dst = malloc(sizeof(char) * len + 1);
	if (dst == NULL)
	{
		va_end(ap);
		return (NULL);
	}
	while (argc-- != 0)
	{
		tmp = va_arg(ap, char *);
		ft_strlcat(dst, tmp, len + 1);
	}
	va_end(ap);
	return (dst);
}

void	ft_cmd_error(char *args, char *cmd)
{
	char	*str;

	if (*args == '\0')
	{
		str = ft_strjoin(PMD, "\n");
		write(2, str, ft_strlen(str));
		exit (126);
	}
	else if (cmd == NULL)
	{
		str = ft_strjoin(CNF, "\n");
		write(2, str, ft_strlen(str));
		exit(127);
	}
	else
	{
		str = ft_join(3, CNF, cmd, "\n");
		write(2, str, ft_strlen(str));
		exit(127);
	}
}
