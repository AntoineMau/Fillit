/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:29:14 by judumay           #+#    #+#             */
/*   Updated: 2018/12/05 16:44:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		ft_len(char *data)
{
	int i;

	i = 0;
	while (data[i] != '\n')
		i++;
	return (i + 1);
}
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

int		ft_conversion(t_list *new, int size)
{
	char	*data;
	int		pose1;
	int		pose2;
	int		pose3;
	int		op;

	op = ft_len(new->data);
	if (!(data = (char*)malloc(sizeof(char) * ((size + 1) * size + 1))))
			return (0);
	data = ft_set_carre(data, (size + 1) * size, size + 1);
	if (size <= new->pos1 / op || size <= new->pos1 % op)
		return (0);
	pose1 = (size + 1) * (new->pos1 / op) + new->pos1 % op;
	data[pose1] = 'A' + new->letter;
	if (size <= new->pos2 / op || size <= new->pos2 % op)
		return (0);
	pose2 = (size + 1) * (new->pos2 / op) + new->pos2 % op;
	data[pose2] = 'A' + new->letter;
	if (size <= new->pos3 / op || size <= new->pos3 % op)
		return (0);
	pose3 = (size + 1) * (new->pos3 / op) + new->pos3 % op;
	data[pose3] = 'A' + new->letter;
	if (size <= new->pos4 / op || size <= new->pos4 % op)
		return (0);
	new->pos4 = (size + 1) * (new->pos4 / op) + new->pos4 % op;
	new->pos1 = pose1;
	new->pos2 = pose2;
	new->pos3 = pose3;
	data[new->pos4] = 'A' + new->letter;
	new->data = data;
	return (1);
}

int		ft_placement(t_list *new, char *carre)
{	
	if (carre[new->pos1] == '.' && carre[new->pos2] == '.' && carre[new->pos3] == '.'
	&& carre[new->pos4] == '.')
	{
		carre[new->pos1] = new->letter + 'A';
		carre[new->pos2] = new->letter + 'A';
		carre[new->pos3] = new->letter + 'A';
		carre[new->pos4] = new->letter + 'A';
		return (1);
	}
	return (0);
}

int		ft_backtrack(t_list *new, int i, char *carre)
{
	int j;

	j = 0;
	dprintf(1, "carre debut bactrack x :\n%s\n", carre);
	if (new == NULL)
		return (1);
	dprintf(1, "data :\n%s\npos : %d %d %d %d\n", new->data, new->pos1, new->pos2, new->pos3, new->pos4);
	if (ft_conversion(new, i))
	{
		dprintf(1, "data apres conv :\n%s\npos : %d %d %d %d\n", new->data, new->pos1, new->pos2, new->pos3, new->pos4);
		while (1)
		{
			if (ft_placement(new, carre))
			{
				if ((ft_backtrack(new->next, i, carre)))
					return (1);
			}
			else if (!(ft_decale_right(new, new->data, 'A' + new->letter, i)))
			{
				if (!(ft_decale_down(new, new->data, 'A' + new->letter, i)))
				{
					while (ft_decale_up(new, new->data, 'A' + new->letter, i)
					|| ft_decale_left(new, new->data, 'A' + new->letter, i))
						;
					break ;
				}
				while (ft_decale_left(new, new->data, 'A' + new->letter, i))
					;
			}
			j++;
		}
	}
	if (new->letter == 0)
	{
		i++;
		free(carre);
		if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
			return (0);
		carre = ft_set_carre(carre, (i + 1) * i, i + 1);
		if ((ft_backtrack(new, i, carre)))
			return (1);
	}
	return (0);
}
