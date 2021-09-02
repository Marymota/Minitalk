/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:59:55 by marmota           #+#    #+#             */
/*   Updated: 2021/03/17 21:37:38 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		word_count;
	int		i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		arr_index;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (0);
	ret[count_words(s, c)] = 0;
	arr_index = 0;
	while (*s && *s == c)
		s++;
	j = 0;
	while (s[j])
	{
		i = j;
		while (s[j] && s[j] != c)
			j++;
		ret[arr_index++] = ft_substr(s, i, j - i);
		while (s[j] && s[j] == c)
			j++;
	}
	return (ret);
}
