/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coupe_decale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:36:40 by judumay           #+#    #+#             */
/*   Updated: 2018/12/03 16:52:01 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <stdio.h>

void	pos_hash(t_list *count, char *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	count->pos1 = -1;
	count->pos2 = -1;
	count->pos3 = -1;
	count->pos4 = -1;
	while (j < 4 && data[i])
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
			j++;
		(j == 1 && count->pos1 == -1) ? count->pos1 = i : j;
		(j == 2 && count->pos2 == -1) ? count->pos2 = i : j;
		(j == 3 && count->pos3 == -1) ? count->pos3 = i : j;
		(j == 4 && count->pos4 == -1) ? count->pos4 = i : j;
		i++;
	}
}

int		ft_decale_up(t_list *ct, char *data, int c)
{
	int		cnt;

	cnt = 0;
	pos_hash(ct, data);
	if (ct->pos1 > 4)
	{
		ft_change(ct, data, 5, 'A' + c);
		return (1);
	}
	return (0);
}

int		ft_decale_left(t_list *ct, char *data, int c)
{
	int		cnt;

	cnt = 0;
	pos_hash(ct, data);
	if (ct->pos1 % 5 > 0 && ct->pos2 % 5 > 0 && ct->pos3 % 5 > 0
	&& ct->pos4 % 5 > 0)
	{
		ft_change(ct, data, 1, 'A' + c);
		return (1);
	}
	return (0);
}

int		ft_decale_down(t_list *ct, char *data, int c)
{
	int		cnt;

	cnt = 0;
	pos_hash(ct, data);
	if (ct->pos1 < 14)
	{
		ft_change(ct, data, -5, 'A' + c);
		return (1);
	}
	return (0);
}

int		ft_decale_right(t_list *ct, char *data, int c)
{
	int		cnt;

	cnt = 0;
	pos_hash(ct, data);
	if (ct->pos1 % 5 < 3 && ct->pos2 % 5 < 3 && ct->pos3 % 5 < 3
	&& ct->pos4 % 5 < 3)
	{
		ft_change(ct, data, -1, 'A' + c);
		return (1);
	}
	return (0);
}
