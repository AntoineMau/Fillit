/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:53:49 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	int				end;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && s[end]
			&& end > (int)start)
		end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
