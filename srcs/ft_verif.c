/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:12:07 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/22 17:41:34 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

int		ft_verif(char *str)
{
	int		i;
	t_liste	cnt_line;

	cnt_line.x = 0;
	cnt_line.y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] != '\n' && str[i + 1] != '\0')
				cnt_line.y++;
			else
				cnt_line.y = 0;
			if ((str[i + 1] == '\n' || str[i + 1] == '\0') && cnt_line.y != 4)
				return (-1);
			if (cnt_line.x != 4 && (str[i - 1] == '.' || str[i - 1] == '#'))
				return (-1);
			cnt_line.x = 0;
		}
		else if (str[i] == '.' || str[i] == '#')
			cnt_line.x++;
		else
			return (-1);
		if (cnt_line.x > 4 || cnt_line.y > 4)
			return (-1);
		i++;
	}
	return (0);
}
