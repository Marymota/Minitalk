/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:28:13 by marmota           #+#    #+#             */
/*   Updated: 2021/02/15 19:28:14 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(nmemb * size);
	if (!ret)
		return (0);
	else
	{
		ft_bzero(ret, nmemb * size);
		return (ret);
	}
	return (0);
}
