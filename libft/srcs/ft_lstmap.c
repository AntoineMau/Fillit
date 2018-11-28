/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:02:23 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*begin;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	if (!(elem = ft_lstnew(tmp->content, tmp->content_size)))
		return (0);
	begin = elem;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(elem->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (0);
		elem = elem->next;
		lst = lst->next;
	}
	return (begin);
}
