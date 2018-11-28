/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:43:55 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = (char*)dest;
	tmp_src = (char*)src;
	i = 0;
	if (dest < src)
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	else
		while (n--)
			tmp_dest[n] = tmp_src[n];
	return (dest);
}
