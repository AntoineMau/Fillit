/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:58:58 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	while (to_find[size])
		size++;
	if (size == 0)
		return ((char*)str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
			if (j++ == size - 1)
				return ((char*)str + i);
	}
	return (0);
}
