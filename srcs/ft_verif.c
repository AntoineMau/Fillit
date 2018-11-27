/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:12:07 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/27 09:54:37 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

int		ft_verif(t_liste *lst)
{
	int i;

	i = 0;
	while (lst->next)
	{
		while (lst->data)
		{
			if (lst->data[i] == '.')
				lst->point++;
			if (lst->data[i] == '#')
				lst->hashtag++;
			if (lst->data[i] == '\n')
				lst->n++;
			if (lst->data[i] == '.' || lst->data[i] == '#'
								|| lst->data[i] == '\n')
				i++;
		}
		if (i != 20 || lst->hashtag != 4 || lst->point != 12 || lst->n != 4)
			return (0);
		lst = lst->next;
	}
	return (1);
}
