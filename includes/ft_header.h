/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:21:14 by anmauffr          #+#    #+#             */
/*   Updated: 2018/12/03 18:12:54 by judumay          ###   ########.fr       */
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

typedef struct	s_count
{
	int				n;
	int				point;
	int				hashtag;
}				t_count;

typedef struct	s_list
{
	char			*data;
	int				pos1;
	int				pos2;
	int				pos3;
	int				pos4;
	struct s_list	*next;
}				t_list;


void			ft_putendl(char const *s);
void			ft_lstnext(t_list **begin, char *data, int k);
void			pos_hash(t_list *count, char *data);
void			*ft_memcpy(char *dst, char *src, size_t n, int k);
int				ft_verif_args(int ac, char **av, char *buf, t_count *count);
int				ft_check_n(char *str, int i, int n);
int				ft_check_str(char *str, t_count *count);
int				ft_check_neib(t_list *new);
int				ft_strlen(char *str);
int				ft_lstlen(t_list *new);
int				ft_change(t_list *ct, char *data, int n, char c);
int				ft_decale_down(t_list *ct, char *data, int c);
int				ft_decale_right(t_list *ct, char *data, int c);
int				main(int ac, char **av);
int				ft_decale_up(t_list *ct, char *data, int c);
int				ft_decale_left(t_list *ct, char *data, int c);
char			*ft_set_carre(char *s, int n, int size);
char			*ft_strdup(char *s);
char			*ft_do_it(t_list *new);
char			*ft_backtrack(t_list *new, int i, char *carre, t_list *begin);
t_list			*ft_verif_lst(t_list *piece, t_list *tmp, char *str);
t_list			*ft_lst_split(t_list *new, char *str);
t_list			*ft_lstnew(char *data, int i);

#endif
