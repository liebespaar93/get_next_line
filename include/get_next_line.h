/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:45:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/05/24 14:18:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

/* get_next_line.c */
char	*ft_buff_split(char **buff_all, int *flag, int rlen);
void	ft_buff_read(char **buff_static, t_list **buff_head, int *flag, int fd);
char	*get_next_line(int fd);

/* get_next_line_utiles.c */
char	*ft_strncpy(char *str, int len);
void	ft_lst_new_add_back(t_list **lst, void *data);
int		ft_lst_datalen(t_list **lst);
char	*ft_lst_malloc(t_list **lst);

#endif
