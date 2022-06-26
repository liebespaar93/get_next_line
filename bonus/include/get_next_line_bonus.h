/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:45:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/05/24 15:45:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_fd
{
	int				fd;
	void			*data;
	struct s_fd		*next;
}	t_fd;

/* get_next_line.c */
char	*ft_buff_split(char **buff_all, int *flag, int rlen);
void	ft_buff_read(char **buff_static, t_list **buff_head, int *flag, int fd);
char	*get_next_line(int fd);
t_fd	*ft_lst_fd_addfront(t_fd **fd_static, int fd, char **buff_static);
char	*ft_lst_fd_find(t_fd **fd_static, int fd);
/* get_next_line_utiles.c */
char	*ft_strncpy(char *str, int len);
void	ft_lst_new_add_back(t_list **lst, void *data);
int		ft_lst_datalen(t_list **lst);
char	*ft_lst_malloc(t_list **lst);

#endif
