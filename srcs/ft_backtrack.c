/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:29:14 by judumay           #+#    #+#             */
/*   Updated: 2018/12/03 18:36:24 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		ft_placement(char *carre, t_list *new)
{
	int		i;
	int		j;
	int		k;
	int		l;

	k = 0;
	l = -1;
	while (carre[++l])
	{
		j = -1;
		i = l;
		while (new->data[++j])
		{
			if (new->data[j] >= 'A' && new->data[j] <= 'Z' && carre[i] == '.')
			{
				carre[i] = new->data[j];
				k++;
			}
			if (carre[i] == '\n' || new->data[j] == '\n')
			{
				while (carre[i] != '\n' && carre[i])
					i++;
				while (new->data[j] != '\n' && new->data[j])
					j++;
			}
			i++;
		}
		if (k == 4)
			return (1);
	}
	return (0);
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

char	*ft_backtrack(t_list *new, int i, char *carre, t_list *begin)
{
	if (new == NULL)
		return (0);
	while (!ft_placement(carre, new))
	{
		i++;
		free(carre);
		new = begin;
		if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
			return (NULL);
		carre = ft_set_carre(carre, (i + 1) * i, i + 1);
	}
	ft_backtrack(new->next, i, carre, begin);
	dprintf(1, "carre = \n%s\n", carre);
	return (carre);
}
