/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:52:37 by marmota           #+#    #+#             */
/*   Updated: 2021/03/04 22:28:42 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(tmp, del);
		}
		*lst = 0;
	}
}
