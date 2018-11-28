/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/11/28 12:49:07 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

#include <stdio.h>

int		main(int ac, char **av)
{
	char	str[BUFF_SIZE+ 1];
	t_liste	piece;

	piece.n = 0;
	piece.hashtag = 0;
	piece.point  = 0;
	if (ft_verif_args(ac, av, str, &piece) < 0)
		ft_putendl("error");
	//new = ft_split_piece(piece, str);
	printf("%s", str);
	printf("data : %s", piece.data);
	return (0);
}
