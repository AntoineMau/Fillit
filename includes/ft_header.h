/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:21:14 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/27 19:03:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 4096
# define ERROR  ft_putendl("error")

typedef struct	s_liste
{
	char			*data;
	int				x;
	int				y;
	int				n;
	int				hashtag;
	int				point;
	struct s_liste	*next;
}				t_liste;

int				main(int ac, char **av);
int				ft_verif_args(int ac, char **av);

#endif
