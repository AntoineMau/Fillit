/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 13:34:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

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
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (-1);
	}
	if ((ft_verif_args(av, str, &piece) == -1) ||
	!(new = ft_verif_lst(new, tmp, str)))
	{
		ft_putendl("error");
		return (0);
	}
	free(tmp);
	finish = ft_do_it(new);
	write(1, finish, ft_strlen(finish));
	return (0);
}
