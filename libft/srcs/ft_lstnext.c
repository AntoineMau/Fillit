/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:19:09 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/28 13:57:49 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstnext(t_list **begin_list, void *content, size_t content_size)
{
	t_list	*elem;

	if (*begin_list)
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_lstnew(content, content_size);
	}
	else
		*begin_list = ft_lstnew(content, content_size);
}
