/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:43 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/22 17:48:47 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		test;
	char	*str;
	int 	i;

	i = 0;
	(void)ac;
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	test = get_next_line(fd, &str);
	while (test > 0)
		test = get_next_line(fd, &str);
	ft_putstr(str);
	if (test == -1 || ft_verif(str) == -1)
	{
		printf("bad");
		return (-1);
	}
	printf("good");
	return (0);
}
