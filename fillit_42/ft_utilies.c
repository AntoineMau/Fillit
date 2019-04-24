/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:45:56 by judumay           #+#    #+#             */
/*   Updated: 2019/04/24 18:10:15 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(char *dst, char *src, int n, int k)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((char*)src)[i] == '#')
			((char*)dst)[i] = 'A' + k;
		else
			((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putendl(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (!(str = (char*)malloc(sizeof(str) * (i))))
		return (NULL);
	while (j <= i)
	{
		str[j] = s1[j];
		j++;
	}
	return (str);
}
