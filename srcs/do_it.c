/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:57:34 by judumay           #+#    #+#             */
/*   Updated: 2018/11/30 15:07:43 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

char	*ft_change(t_count *ct, char *data, int n, char c)
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
	return (data);
}

static void	ft_set_carre(char *s, int n, int size)
{
	int		i;
	char	*str;

	str = s;
	i = -1;
	while (++i < n)
	{
		if (i % size == size - 1)
			str[i] = '\n';
		else
			str[i] = '.';
	}
	str[i] = '\0';
	s = str;
}

char		*ft_do_it(t_list *new)
{
	char	*carre;
	int		i;
	int		c;
	t_list	*begin;

	begin = new;
	i = 4;
	c = 0;
	if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
		return (NULL);
	ft_set_carre(carre, (i + 1) * i, i + 1); 
	while (new)
	{
		new->data = ft_decale_up(new->data, c);
		new->data = ft_decale_left(new->data, c);
		new->data = ft_decale_down(new->data, c);
		new->data = ft_decale_right(new->data, c);
		printf("data :\n%s", new->data);
		c++;
		new = new->next;
	}
	return (carre);
}
