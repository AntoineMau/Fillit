/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/11/29 14:49:34 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

int		main(int ac, char **av)
{
	char	str[BUFF_SIZE + 1];
	t_count	piece;
	t_list	*new;
	t_list	*temp;

	new = NULL;
	temp = NULL;
	piece.n = 0;
	piece.hashtag = 0;
	piece.point = 0;
	if ((ft_verif_args(ac, av, str, &piece) == -1) ||
	!(new = ft_verif_lst(new, temp, str)))
	{
		ft_putendl("error");
		return (-1);
	}
	free(temp);
	return (0);
}
