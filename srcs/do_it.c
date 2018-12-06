/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:57:34 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 10:14:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

char	*ft_set_carre(char *s, int n, int size)
{
	int		i;
	char	*str;

	i = -1;
	str = s;
	while (++i < n)
	{
		if (i % size == size - 1)
			str[i] = '\n';
		else
			str[i] = '.';
	}
	str[i] = '\0';
	s = str;
	return (s);
}

int		ft_len(char *data)
{
	int i;

	i = 0;
	while (data[i] != '\n')
		i++;
	return (i + 1);
}

int		ft_change(t_list *ct, char *data, int n, char c)
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

char	*ft_do_it(t_list *new)
{
	int		c;
	char	*carre;
	t_list	*begin;
	char	*finish[1];

	c = 0;
	new->letter = 0;
	begin = new;
	while (new)
	{
		while (ft_decale_up(new, new->data, c, 4)
		|| ft_decale_left(new, new->data, c, 4))
			;
		c++;
		new->letter = c - 1;
		new = new->next;
	}
	new = begin;
	c = 2;
	if (!(carre = (char*)malloc(sizeof(char) * ((c + 1) * c + 1))))
		return (NULL);
	carre = ft_set_carre(carre, (c + 1) * c, c + 1);
	ft_backtrack(new, c, carre, finish);
	return (finish[0]);
}
