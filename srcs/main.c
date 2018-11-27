/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:43 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/27 09:49:51 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

#define ERROR  ft_putstr("error\n")

t_liste	*ft_strcasse(char *str)
{
	t_liste *lst;
	int i;

	i = 0;
	lst = NULL;
	while (str)
	{
		while (i < 20)
		{

			dprintf(1, "lst position %d : %s\n", i, lst->data);
			lst = lst->next;
			str++;
			i++;
		}
	}
	return (lst);
}


int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	t_liste	*list;

	(void)ac;
	list = NULL;
	str = (char*)malloc(sizeof(*str) * 1000);
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	list = ft_strcasse(str);
	if (!ft_verif(list))
		ERROR;
	return (0);
}
