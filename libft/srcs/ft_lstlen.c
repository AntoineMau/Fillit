/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:49:05 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_lstlen(t_list *lst)
{
	int		len;
	t_list	*elem;

	if (!lst)
		return (0);
	len = 0;
	elem = lst;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
