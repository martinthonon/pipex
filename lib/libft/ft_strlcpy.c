/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:44:52 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:44:56 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	const char	*s;

	s = src;
	if (n < 1)
		return (ft_strlen(src));
	while (*s && (n-- > 1))
		*dst++ = *s++;
	*dst = '\0';
	return (ft_strlen(src));
}
