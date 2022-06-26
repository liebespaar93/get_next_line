/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:00:41 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/26 19:24:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*ft_buff_split(char **buff_all, int *flag, int rlen)
{
	char	*tmp;
	char	*result;
	int		enter_len;
	int		leave_len;

	enter_len = 0;
	leave_len = 0;
	tmp = *buff_all;
	while (*tmp && ++enter_len && rlen--)
		if (*tmp++ == '\n' && (*flag)--)
			break ;
	while (*tmp++ && rlen--)
		leave_len++;
	if (!leave_len)
	{
		result = *buff_all;
		*buff_all = NULL;
		return (result);
	}
	result = ft_strncpy(*buff_all, enter_len);
	tmp = ft_strncpy(*buff_all + enter_len, leave_len);
	free(*buff_all);
	*buff_all = tmp;
	return (result);
}

void	ft_buff_read(char **buff_static, t_list **buff_head, int *flag, int fd)
{
	int		rlen;

	*buff_static = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buff_static)
		return ;
	rlen = (int)read(fd, *buff_static, BUFFER_SIZE);
	if (rlen <= 0)
	{
		free(*buff_static);
		*buff_static = NULL;
		*flag = 0;
		return ;
	}
	(*buff_static)[rlen] = '\0';
	ft_lst_new_add_back(buff_head, ft_buff_split(buff_static, flag, rlen));
}

char	*get_next_line(int fd)
{
	static char	*buff_static;
	t_list		*buff_head;
	char		*buff;
	int			flag;

	buff_head = NULL;
	flag = 1;
	if (buff_static)
		ft_lst_new_add_back(&buff_head, \
		(void *)ft_buff_split(&buff_static, &flag, -1));
	while (flag)
		ft_buff_read(&buff_static, &buff_head, &flag, fd);
	buff = ft_lst_malloc(&buff_head);
	return (buff);
}
