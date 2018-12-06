/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:29:14 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 15:38:31 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdlib.h>

int		ft_conversion(t_list *new, int size)
{
	char	*dat;
	int		op;

	op = ft_len(new->data);
	if (!(dat = (char*)malloc(sizeof(char) * ((size + 1) * size + 1))))
		return (0);
	if (size <= new->pos1 / op || size <= new->pos1 % op || size <= new->pos2 /
	op || size <= new->pos2 % op || size <= new->pos3 / op || size <= new->pos3
	% op || size <= new->pos4 / op || size <= new->pos4 % op)
	{
		free(dat);
		return (0);
	}
	dat = ft_set_carre(dat, (size + 1) * size, size + 1);
	new->pos1 = (size + 1) * (new->pos1 / op) + new->pos1 % op;
	new->pos2 = (size + 1) * (new->pos2 / op) + new->pos2 % op;
	new->pos3 = (size + 1) * (new->pos3 / op) + new->pos3 % op;
	new->pos4 = (size + 1) * (new->pos4 / op) + new->pos4 % op;
	dat[new->pos1] = 'A' + new->letter;
	dat[new->pos2] = 'A' + new->letter;
	dat[new->pos3] = 'A' + new->letter;
	dat[new->pos4] = 'A' + new->letter;
	free(new->data);
	new->data = dat;
	return (1);
}

int		ft_placement(t_list *new, char *carre)
{
	if (carre[new->pos1] == '.' && carre[new->pos2] == '.' &&
	carre[new->pos3] == '.' && carre[new->pos4] == '.')
	{
		carre[new->pos1] = new->letter + 'A';
		carre[new->pos2] = new->letter + 'A';
		carre[new->pos3] = new->letter + 'A';
		carre[new->pos4] = new->letter + 'A';
		return (1);
	}
	return (0);
}

int		ft_clean(char c, char *carre)
{
	int i;

	i = -1;
	while (carre[++i])
		if (carre[i] == c)
			carre[i] = '.';
	return (1);
}

int		ft_decale(t_list *new, int i)
{
	if (!(ft_decale_right(new, new->data, 'A' + new->letter, i)))
	{
		if (!(ft_decale_down(new, new->data, 'A' + new->letter, i)))
		{
			while (ft_decale_up(new, new->data, 'A' + new->letter, i)
			|| ft_decale_left(new, new->data, 'A' + new->letter, i))
				;
			return (0);
		}
		while (ft_decale_left(new, new->data, 'A' + new->letter, i))
			;
	}
	return (1);
}

int		ft_backtrack(t_list *new, int i, char *carre, char *finish[1])
{
	if (new == NULL && (finish[0] = ft_strdup(carre)))
		free(carre);
	if (finish[0])
		return (1);
	if (ft_conversion(new, i))
		while (1)
		{
			if (ft_placement(new, carre))
				if (ft_backtrack(new->next, i, carre, finish))
					return (1);
			if (ft_clean(new->letter + 'A', carre) && (!ft_decale(new, i)))
				break ;
		}
	if (new->letter == 0 && (++i))
	{
		free(carre);
		if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
			return (0);
		carre = ft_set_carre(carre, (i + 1) * i, i + 1);
		if ((ft_backtrack(new, i, carre, finish)))
			return (1);
	}
	return (0);
}
