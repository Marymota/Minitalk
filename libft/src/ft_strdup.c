/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:28:07 by marmota           #+#    #+#             */
/*   Updated: 2021/02/15 19:28:09 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;

	len = ft_strlen(s);
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
