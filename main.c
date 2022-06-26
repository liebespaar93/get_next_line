/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:12:44 by kyoulee           #+#    #+#             */
/*   Updated: 2022/05/24 15:45:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <get_next_line.h>

int	main(void)
{
	char			*line;
	int				fd;
	int				fd2;
	int				i;

	fd = open("check.txt", O_RDONLY);
	i = 0;
	fd2 = open("check2.txt", O_RDONLY);
	while (i++ < 300)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
    while (i++ < 600)
    {
        line = get_next_line(fd2);
        if (!line)
            break ;
        printf("%s", line);
        free(line);
    }
	close(fd);
	close(fd2);
	system("leaks a.out");
	return (0);
}
