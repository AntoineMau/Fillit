/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:29:14 by judumay           #+#    #+#             */
/*   Updated: 2018/12/04 09:38:43 by judumay          ###   ########.fr       */
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

int		ft_placement(char *carre, t_list *new)
{
	int		i;
	int		compteur;

	compteur = 0;
	i = -1;
	if (!ft_check_point(carre))
		return (0);
	while (carre[++i])
	{
		compteur = 0;
		if (ft_test(new, carre) == 1)
			return (1);
		else
		{
			if (!ft_decale_right(new, new->data, 'A' + new->letter))
			{
				if (!ft_decale_down(new, new->data, 'A' + new->letter))
					break ;
				while (ft_decale_left(new, new->data, 'A' + new->letter)
					;
			}
		}
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
