/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coupe_decale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:36:40 by judumay           #+#    #+#             */
/*   Updated: 2018/11/30 15:04:46 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

void		pos_hash(t_count *count, char *data)
{
	int		i;;
	int		j;

	i = 0;
	j = 0;
	count->pos1 = 0;
	count->pos2 = 0;
	count->pos3 = 0;
	count->pos4 = 0;
	while (j < 4 && data[i])
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
			j++;
		(j == 1 && count->pos1 == 0) ? count->pos1 = i : j;
		(j == 2 && count->pos2 == 0) ? count->pos2 = i : j;
		(j == 3 && count->pos3 == 0) ? count->pos3 = i : j;
		(j == 4 && count->pos4 == 0) ? count->pos4 = i : j;
		i++;
	}
}

char	*ft_decale_up(char *data, int c)
{
	int		cnt;
	t_count	ct;

	cnt = 0;
	pos_hash(&ct, data);
	while (ct.pos1 > 4)
		data = ft_change(&ct, data, 5, 'A'+ c);
	return(data);
}

char	*ft_decale_left(char *data, int c)
{
	int		cnt;
	t_count	ct;

	cnt = 0;
	pos_hash(&ct, data);
	while (ct.pos1 % 5 > 0 && ct.pos2 % 5 > 0 && ct.pos3 % 5 > 0 && ct.pos4 % 5 > 0)
		data = ft_change(&ct, data, 1, 'A' + c);
	return(data);
}

char	*ft_decale_right(char *data, int c)
{
	int		cnt;
	t_count	ct;

	cnt = 0;
	pos_hash(&ct, data);
	c = 0;
	return(data);
}

char	*ft_decale_down(char *data, int c)
{
	int		cnt;
	t_count	ct;

	cnt = 0;
	pos_hash(&ct, data);
	c = 0;
	return(data);
}
