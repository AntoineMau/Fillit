/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:12:37 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:40 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lst_at(t_list *begin, unsigned int nbr)
{
	unsigned int	i;
	t_list			*elem;

	if (!begin)
		return (0);
	i = 0;
	elem = begin;
	while (i < nbr)
	{
		if (!elem)
			return (0);
		elem = elem->next;
		i++;
	}
	return (elem);
}
