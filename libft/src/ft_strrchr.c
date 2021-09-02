/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:39:30 by marmota           #+#    #+#             */
/*   Updated: 2021/02/24 15:44:24 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*start;

	str = (char *)s;
	start = 0;
	while (*str)
	{
		if (*str == (char)c)
			start = str;
		++str;
	}
	if (c == 0)
		start = str;
	return (start);
}
