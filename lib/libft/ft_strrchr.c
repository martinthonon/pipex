/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:47:12 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:47:37 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*strr;
	const char	i = c;

	strr = NULL;
	while (1)
	{
		if (*s == i)
			strr = s;
		if (*s == '\0')
			return ((char *) strr);
		++s;
	}
}
