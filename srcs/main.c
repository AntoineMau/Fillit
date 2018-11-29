/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:29 by judumay           #+#    #+#             */
/*   Updated: 2018/11/29 17:05:39 by anmauffr         ###   ########.fr       */
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
	if ((ft_verif_args(ac, av, str, &piece) == -1) ||
	!(new = ft_verif_lst(new, tmp, str)))
	{
		ft_putendl("error");
		return (-1);
	}
	free(tmp);
	ft_putendl(finish = ft_do_it(new));
	return (0);
}
