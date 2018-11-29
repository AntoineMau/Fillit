/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:12:07 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/29 14:30:05 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

int		ft_check_neib(t_list *new)
{
	int		voisin;
	int		i;
	char	*tmp;

	while (new)
	{
		tmp = ft_strdup(new->content);
		voisin = 0;
		i = -1;
		while (++i < 20)
			if (((char*)new->content)[i] == '#')
			{
				(tmp[i + 1] == '#') ? voisin++ : voisin;
				(tmp[i - 1] == '#') ? voisin++ : voisin;
				(i < 15 && tmp[i + 5] == '#') ? voisin++ : voisin;
				(i > 5 && tmp[i - 5] == '#') ? voisin++ : voisin;
			}
		free(tmp);
		if (i != 0 && voisin != 6 && voisin != 8)
			return (-1);
		new = new->next;
	}
	return (1);
}

int		ft_check_n(char *str, int i, int n)
{
	if (str[i - 1] == '.' || str[i - 1] == '#')
		return (1);
	if (n % 5 == 4 && n > 5)
		n++;
	else if (n % 5 == 4 && n < 5)
		return (1);
	if (n % 5 == 0 && str[i - 1] == '\n' && (str[i + 1] == '.' ||
	str[i + 1] == '#' || str[i + 1] == '\0'))
		return (1);
	return (-1);
}

int		ft_check_str(char *str, t_count *count)
{
	int		i;

	i = 0;
	count->point = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count->point++;
		if (str[i] == '\n')
		{
			if (ft_check_n(str, i, count->n) == -1)
				return (-1);
			count->n++;
		}
		if (str[i] == '#')
			count->hashtag++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (-1);
		i++;
	}
	if (count->n > 129 || count->n % 5 != 4 || count->point > 312 ||
	count->point % 12 != 0 || count->hashtag > 104 || count->hashtag % 4 != 0)
		return (-1);
	return (1);
}

int		ft_verif_args(int ac, char **av, char *buf, t_count *count)
{
	int		fd;
	int		ret;

	if (ac != 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ft_check_str(buf, count) == -1)
		return (-1);
	return (0);
}
