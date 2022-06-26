/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:32:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/26 19:23:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*ft_strncpy(char *str, int len)
{
	char	*tmp;
	char	*result;

	if (len == 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) *(len + 1));
	if (!tmp)
		return (NULL);
	result = tmp;
	tmp[len] = '\0';
	while (len--)
		*tmp++ = *str++;
	return (result);
}

void	ft_lst_new_add_back(t_list **lst, void *data)
{
	t_list	*lst_move;
	t_list	*lst_new;

	lst_new = (t_list *)malloc(sizeof(t_list));
	if (lst_new == NULL)
		return ;
	lst_new->next = NULL;
	lst_new->data = data;
	if (*lst == NULL || lst_new == NULL)
	{
		if (*lst == NULL)
			*lst = lst_new;
		return ;
	}
	lst_move = *lst;
	while (lst_move->next)
		lst_move = lst_move->next;
	lst_move->next = lst_new;
}

int	ft_lst_datalen(t_list **lst)
{
	t_list	*lst_move;
	char	*tmp;
	int		len;

	if (*lst == NULL)
		return (0);
	lst_move = *lst;
	len = 0;
	while (lst_move)
	{
		tmp = lst_move->data;
		while (*tmp++)
			len++;
		lst_move = lst_move->next;
	}
	return (len);
}

char	*ft_lst_malloc(t_list **lst)
{
	t_list	*lst_move;
	t_list	*tmp_lst;
	char	*tmp;
	char	*result;
	int		len;

	if (*lst == NULL)
		return (NULL);
	lst_move = *lst;
	len = ft_lst_datalen(lst);
	result = (char *)malloc(len + 1);
	lst_move = *lst;
	len = 0;
	while (lst_move)
	{
		tmp_lst = lst_move->next;
		tmp = lst_move->data;
		while (*tmp)
			result[len++] = *tmp++;
		free(lst_move->data);
		free(lst_move);
		lst_move = tmp_lst;
	}
	result[len] = '\0';
	return (result);
}
