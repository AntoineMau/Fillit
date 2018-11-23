/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:43 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/23 10:20:28 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		test;
	char	*tmp;
	char	*str;
	int 	i;

	i = 0;
	(void)ac;
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	test = 1;
	str = (char*)malloc(sizeof(char) * 1000);
	while (test > 0)
	{
		test = get_next_line(fd, &tmp);
		ft_strjoin(str, tmp);
		dprintf(1, "tmp : %s\n", tmp);
		free(tmp);
	}
	dprintf(1, "str : %s\n", str);
	if (test == -1 || ft_verif(str) == -1)
	{
		printf("bad");
		return (-1);
	}
	printf("good");
	return (0);
}
