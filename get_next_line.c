/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:52:11 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/30 05:20:12 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

char *cut_str(char *pos_buff, char **str)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = NULL;
	// printf("pos_buuf =[%s]", pos_buff);
	while (pos_buff[i] && pos_buff[i] != '\n')
		i++;
	// printf("i = %d\n", i);
	*str = ft_substr(pos_buff, 0, i);
	if (!str)
	{
		free(pos_buff);
		return (NULL);
	}
	if (pos_buff[i])
	{
		tmp = ft_substr(pos_buff, i  + 1, ft_strlen(pos_buff) - (i + 1));
		// printf("tmp = %s\n", tmp);
		if (!tmp)
		{
			free(pos_buff);
			return (NULL);
		}
		pos_buff = tmp;
	}
	else
	{
		free(pos_buff);
		return (NULL);
	}
	return (pos_buff);
}

char    *get_next_line(int fd)
{
	// char		*tmp = NULL;
	char		*str = NULL;
	static char	*pos_buff = NULL;
	char 		buff[BUFFER_SIZE + 1];
	int			c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!pos_buff)
		pos_buff = ft_strdup("");
	while (!ft_strchr(pos_buff, '\n'))
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c <= 0)
			break ;
		buff[c] = '\0';
		pos_buff = ft_strjoin(pos_buff, buff);
		//pos_buff = ft_strdup(tmp);
	}
	pos_buff = cut_str(pos_buff, &str);
	// if (!strcmp(str, ""))
	// 	return(NULL);
	return (str);
}

int main(int ac, char *av[])
{
	int fd;
	int num = 2;
	char *str =NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0)
		return (1);
	while (num)
	{
		str = get_next_line(fd);
		printf("[%s]\n", str);
		num--;
	}
		
	return (0);
}