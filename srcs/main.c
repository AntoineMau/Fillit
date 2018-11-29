/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/11/29 10:03:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

#include <stdio.h>

t_list	*ft_lst_split(t_list *new, char *str)
{
	int		i;
	t_list	*begin;

	i = 0;
	ft_lstnext(&new, (void*)&str[i], 19);
	i += 21;
	begin = new;
	while (str[i])
	{
		ft_lstnext(&new->next, (void*)&str[i], 19);
		i += 21;
		new = new->next;
	}
	return (begin);
}


int		main(int ac, char **av)
{
	char	str[BUFF_SIZE+ 1];
	t_list	piece;
	t_list *new;
	t_list *temp;

	new = NULL;
	temp = NULL;
	piece.n = 0;
	piece.hashtag = 0;
	piece.point  = 0;
	if (ft_verif_args(ac, av, str, &piece) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	new = ft_lst_split(temp, str);
	free(temp);
	while (new)
	{
		if (ft_check_neib(new) == -1)
		{
			ft_putendl("error");
			return (-1);
		}
		new = new->next;
	}
	ft_putendl("\nGG");
	free(temp);
	return (0);
}
