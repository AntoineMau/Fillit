/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:15:31 by judumay           #+#    #+#             */
/*   Updated: 2018/12/05 17:59:14 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

t_list	*ft_lstnew(char *data, int i)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!(data))
		new->data = NULL;
	else
	{
		if (!(new->data = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		ft_memcpy(new->data, data, 20, i);
		new->data[20] = '\0';
	}
	new->next = NULL;
	return (new);
}

void	ft_lstnext(t_list **begin, char *data, int k)
{
	*begin = ft_lstnew(data, k);
}

t_list	*ft_lst_split(t_list *new, char *str)
{
	int		i;
	int		k;
	t_list	*begin;

	i = 0;
	k = 0;
	ft_lstnext(&new, &str[i], k++);
	i += 21;
	begin = new;
	while (i < ft_strlen(str))
	{
		ft_lstnext(&new->next, &str[i], k++);
		i += 21;
		new = new->next;
	}
	return (begin);
}

t_list	*ft_verif_lst(t_list *piece, t_list *tmp, char *str)
{
	t_list	*begin;

	piece = ft_lst_split(tmp, str);
	free(tmp);
	begin = piece;
	while (piece)
	{
		if (ft_check_neib(piece) == -1)
			return (NULL);
		piece = piece->next;
	}
	free(piece);
	return (begin);
}
