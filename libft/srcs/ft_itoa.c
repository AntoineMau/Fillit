/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:28:02 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/14 16:57:26 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putnbr_in_str(int n, int *i, char *str)
{
	if (n == -2147483648)
		ft_strcpy(str, "-2147483648");
	else if (n < 0)
	{
		str[0] = '-';
		i[0] = 0;
		ft_putnbr_in_str(-n, i, str);
	}
	if (n >= 10)
		ft_putnbr_in_str(n / 10, i, str);
	i[0]++;
	if (n >= 0)
		str[i[0]] = n % 10 + '0';
}

char		*ft_itoa(int n)
{
	int		j;
	int		nbr;
	int		i[1];
	char	*str;

	nbr = n;
	j = 0;
	if (nbr < 0)
		j++;
	while (nbr /= 10)
		j++;
	i[0] = -1;
	if (!(str = (char*)malloc(sizeof(char) * j + 2)))
		return (0);
	ft_bzero(str, 12);
	ft_putnbr_in_str(n, i, str);
	return (str);
}
