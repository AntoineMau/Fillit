/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:56:58 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/28 19:25:27 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_letters(char const *s, char c, int find_words)
{
	int		i;
	int		letters;
	int		word;
	int		nb_words;

	i = 0;
	word = 0;
	nb_words = 0;
	letters = 0;
	while (s[i])
	{
		if (s[i] == c)
			word = 0;
		else if (s[i] != c && word++ == 0)
			nb_words++;
		if (nb_words == find_words && s[i] != c)
			letters++;
		i++;
	}
	return (letters);
}

static int	ft_words(char const *s, char c)
{
	int		i;
	int		word;
	int		nb_words;

	i = 0;
	word = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] == c)
			word = 0;
		else if (s[i] != c && word++ == 0)
			nb_words++;
		i++;
	}
	return (nb_words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s)
		return (0);
	if (!(str = (char**)malloc(sizeof(*str) * (ft_words(s, c) + 1))))
		return (0);
	i = 0;
	k = -1;
	while (i < ft_words(s, c) && k++ != -10)
	{
		j = 0;
		if (!(str[i] = (char*)malloc(sizeof(char) *
				(ft_letters(s, c, i + 1) + 1))))
			return (0);
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			str[i][j++] = s[k++];
		str[i++][j] = '\0';
	}
	str[i] = 0;
	return (str);
}
