/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:29:14 by judumay           #+#    #+#             */
/*   Updated: 2018/12/04 17:47:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		ft_check_point(char *carre)
{
	int i;

	i = 0;
	while (*carre)
	{
		if (*carre == '.')
			i++;
		carre++;
	}
	if (i >= 4)
		return (1);
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

int		ft_cal_j(char *carre, int pos, char *str, int j)
{
	int		i;

	while (pos >= 5)
	{
		i = pos;
		while (str[i] && str[i] == '.')
			i++;
		pos -= 5;
		dprintf(1, "char : %c\n", str[i]);
		if (str[i] == '\n')
		{
			dprintf(1, "hey");
			while (carre[j] != '\n')
				j++;
			j++;
		}
	}
	return (j + pos % 5);
}

int		ft_placement(t_list *new, char *carre, int j, int i)
{
	(void)i;
	if (carre[j] != '.' && !carre[j] && !ft_check_point(carre))
		return (0);
	carre[j] = 'A' + new->letter;
	j = ft_cal_j(carre, new->pos2, new->data, j);
	if (carre[j] != '.' && !carre[j])
		return (0);
	carre[j] = 'A' + new->letter;
	j = ft_cal_j(carre, new->pos3, new->data, j);
	if (carre[j] != '.' && !carre[j])
		return (0);
	carre[j] = 'A' + new->letter;
	j = ft_cal_j(carre, new->pos4, new->data, j);
	if (carre[j] != '.' && !carre[j])
		return (0);
	carre[j] = 'A' + new->letter;
	return (1);
}

char	*ft_clean(char c, char *carre)
{
	int i;

	i = 0;
	while (carre[i])
	{
		if (carre[i] == c)
			carre[i] = '.';
		i++;
	}
	return (carre);
}

int		ft_backtrack(t_list *new, int i, char *carre)
{
	int j;

	j = 0;
	if (new == NULL)
	{
		dprintf(1, "\nfin\n");
		return (1);
	}
	while (carre[j])
	{
		if (ft_placement(new, carre, j, i))
		{
			dprintf(1, "dedans :\n%s\n", carre);
			if (ft_backtrack(new->next, i, carre))
				return (1);
		}
		ft_clean(new->letter + 'A', carre);
		j++;
	}
	if (new->letter == 0)
	{
		i++;
		free(carre);
		if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
			return (0);
		carre = ft_set_carre(carre, (i + 1) * i, i + 1);
		dprintf(1, "new carre : \n%s\n", carre);
		ft_backtrack(new, i, carre);
	}
	return (0);
}
