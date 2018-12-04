/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:57:34 by judumay           #+#    #+#             */
/*   Updated: 2018/12/04 16:01:32 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int				ft_change(t_list *ct, char *data, int n, char c)
{
	data[ct->pos1] = '.';
	data[ct->pos2] = '.';
	data[ct->pos3] = '.';
	data[ct->pos4] = '.';
	ct->pos1 -= n;
	ct->pos2 -= n;
	ct->pos3 -= n;
	ct->pos4 -= n;
	data[ct->pos1] = c;
	data[ct->pos2] = c;
	data[ct->pos3] = c;
	data[ct->pos4] = c;
	return (1);
}

char			*ft_do_it(t_list *new)
{
	int		c;
	char	*carre;
	t_list	*begin;

	c = 0;
	new->letter = 0;
	begin = new;
	while (new)
	{
		while (ft_decale_up(new, new->data, c) != 0 ||
		ft_decale_left(new, new->data, c) != 0)
			;
		c++;
		new->letter = c - 1;
		dprintf(1, "\npos1 : %d pos2: %d pos3: %d pos4: %d\n", new->pos1, new->pos2, new->pos3, new->pos4);
		dprintf(1, "data :\n%s\n letter = %d \n\n\n\n\n\n\n\n\n\n", new->data, new->letter);
		new = new->next;
	}
	new = begin;
	if (!(carre = (char*)malloc(sizeof(char) * ((2 + 1) * 2 + 1))))
		return (NULL);
	carre = ft_set_carre(carre, (2 + 1) * 2, 2 + 1);
	ft_backtrack(new, 2, carre);
	return (carre);
}
