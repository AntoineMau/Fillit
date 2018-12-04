/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/12/04 12:03:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	str[BUFF_SIZE + 1];
	char	*finish;
	t_count	piece;
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = NULL;
	piece.n = 0;
	piece.hashtag = 0;
	piece.point = 0;
	if ((ft_verif_args(ac, av, str, &piece) == -1) ||
	!(new = ft_verif_lst(new, tmp, str)))
	{
		ft_putendl("error");
		return (-1);
	}
	free(tmp);
	finish = ft_do_it(new);
	dprintf(1, "carre = \n%s\n", finish);
	return (0);
}
