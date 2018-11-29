/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:57:34 by judumay           #+#    #+#             */
/*   Updated: 2018/11/29 18:47:14 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

#include <stdio.h>

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

/*int			check_place(char *carre, char *s, int i)
{

}*/

char		*ft_do_it(t_list *new)
{
	int		i;
	int		j;
	int		cnt;
	char	*carre;
	t_list	*begin;

	i = 4;
	begin = new;
	if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
		return (NULL);
	ft_set_carre(carre, (i + 1) * i, i + 1);
	i = -1;
	cnt = 0;
	while (++i < 5)
	{
		if (new->data[i] >= 'A' && new->data[i] <= 'Z')
			cnt++;
		if (i == 4 && cnt == 0)
		{
			j = 0;
			while (new->data[i])
				new->data[j++] = new->data[i++];
			while (new->data[j])
				if (j % 5 != 0)
					new->data[j++] = '.';
				else
					new->data[j++] = '\n';
			i = -1;
		}
		printf("%s\n\n", new->data);
	}
	return (carre);
}
