/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:42:52 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:42:56 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*tmp;
	const char	*dst;

	tmp = malloc(ft_strlen(s) + 1);
	if (!tmp)
		return (tmp);
	dst = tmp;
	while (*s)
		*tmp++ = *s++;
	*tmp = '\0';
	return ((char *)dst);
}
