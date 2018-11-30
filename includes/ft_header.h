/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:21:14 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/30 15:03:24 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 545

typedef struct	s_list
{
	char			*data;
	int				pose;
	struct s_list	*next;
}				t_list;

typedef struct	s_count
{
	int				n;
	int				point;
	int				hashtag;
	int 			pos1;
	int				pos2;
	int				pos3;
	int 			pos4;
}				t_count;

void			ft_putendl(char const *s);
void			ft_lstnext(t_list **begin, char *data, int k);
void			*ft_memcpy(char *dst, char *src, size_t n, int k);
int				ft_verif_args(int ac, char **av, char *buf, t_count *count);
int				ft_check_n(char *str, int i, int n);
int				ft_check_str(char *str, t_count *count);
int				ft_check_neib(t_list *new);
int				ft_strlen(char *str);
int				ft_lstlen(t_list *new);
int				main(int ac, char **av);
char			*ft_strdup(char *s);
char			*ft_do_it(t_list *new);
void			pos_hash(t_count *count, char *data);
char			*ft_change(t_count *ct, char *data, int n, char c);
char			*ft_decale_up(char *data, int c);
char			*ft_decale_left(char *data, int c);
char			*ft_decale_down(char *data, int c);
char			*ft_decale_right(char *data, int c);
void			pos_hash(t_count *count, char *data);
t_list			*ft_verif_lst(t_list *piece, t_list *tmp, char *str);
t_list			*ft_lst_split(t_list *new, char *str);
t_list			*ft_lstnew(char *data, int i);

#endif
