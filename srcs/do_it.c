/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:57:34 by judumay           #+#    #+#             */
/*   Updated: 2018/11/29 15:59:59 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

int		check_place(char *carre, char *s, int i)
{

}

char	*ft_do_it(t_list *new)
{
	char	*carre;
	int		i;
	t_list	*begin;

	i = 2;
	begin = new;
	if (!(carre = (char*)malloc(sizeof(char) * ((i + 1) * i + 1))))
		return (NULL);
	
	
	return (carre);
}
