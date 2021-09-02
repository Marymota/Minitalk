/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:08:48 by marmota           #+#    #+#             */
/*   Updated: 2021/02/19 20:49:57 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_start;
	char	*str_end;
	char	*str;
	int		len;

	if (!s1 || !set)
		return (ft_strdup(""));
	str_start = (char *)s1;
	str_end = str_start + ft_strlen(s1) - 1;
	while (*str_start && ft_strchr(set, *str_start))
		str_start++;
	while (str_end > str_start && ft_strchr(set, *str_end))
		str_end--;
	len = str_end - str_start + 2;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	ft_strlcpy(str, str_start, len);
	return (str);
}
