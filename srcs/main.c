/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:43 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/23 11:59:39 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	(void)ac;
	str = (char*)malloc(sizeof(*str) * 1000);
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	dprintf(1, "%s\n", str);
	if (ret == -1 || ft_verif(str) == -1)
	{
		printf("bad");
		return (-1);
	}
	printf("good");
	return (0);
}
