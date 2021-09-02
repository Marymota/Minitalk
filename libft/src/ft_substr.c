/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:28:07 by marmota           #+#    #+#             */
/*   Updated: 2021/02/26 10:28:08 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start || !len)
		return (ft_strdup(""));
	if (s_len < len)
		len = s_len;
	ret = malloc(++len);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len);
	return (ret);
}
