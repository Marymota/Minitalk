/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:31:50 by marmota           #+#    #+#             */
/*   Updated: 2021/03/04 22:31:51 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
	{
		ft_lstclear(&lst, del);
	}
	ret = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&ret, del);
		}
		lst = lst->next;
		ft_lstadd_back(&ret, tmp);
	}
	return (ret);
}
