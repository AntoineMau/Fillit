/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:15:31 by judumay           #+#    #+#             */
/*   Updated: 2018/11/29 16:08:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

#include <stdio.h>

t_list	*ft_lstnew(char *content, int i)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!(content))
		new->content = NULL;
	else
	{
		if (!(new->content = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		ft_memcpy(new->content, content, 20, i);
		new->content[20] = '\0';
	}
	new->next = NULL;
	return (new);
}

void	ft_lstnext(t_list **begin_list, char *content)
{
	t_list	*elem;
	int		compteur;

	if (*begin_list)
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_lstnew(content, ft_lstlen(new));
		free(elem);
	}
	else
		*begin_list = ft_lstnew(content);
}

t_list	*ft_lst_split(t_list *new, char *str)
{
	int		i;
	t_list	*begin;

	i = 0;
	ft_lstnext(&new, &str[i]);
	i += 21;
	begin = new;
	while (i < ft_strlen(str))
	{
		ft_lstnext(&new->next, &str[i]);
		i += 21;
		new = new->next;
	}
	return (begin);
}

t_list	*ft_verif_lst(t_list *piece, t_list *temp, char *str)
{
	t_list	*begin;

	piece = ft_lst_split(temp, str);
	free(temp);
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
