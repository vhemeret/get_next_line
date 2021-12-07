/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:52:11 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/07 20:24:26 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen( char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*freebuff(char *pos_buff)
{
	free(pos_buff);
	return (NULL);
}

char	*cut_str(char *pos_buff, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (pos_buff[i] && pos_buff[i] != '\n')
		i++;
	*str = ft_substr(pos_buff, 0, i + 1);
	if (!str)
		return (freebuff(pos_buff));
	if (pos_buff[i + 1])
	{
		tmp = ft_substr(pos_buff, i + 1, ft_strlen(pos_buff) - (i + 1));
		if (!tmp)
			return (freebuff(pos_buff));
		free(pos_buff);
		pos_buff = tmp;
	}
	else
		return (freebuff(pos_buff));
	return (pos_buff);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*tmp;
	static char	*pos_buff = NULL;
	char		*buff;
	int			c;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || buff == NULL)
		return (freebuff(buff));
	while (!ft_strchr(pos_buff, '\n'))
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c == -1)
			return (freebuff(buff));
		else if (c == 0)
		{
			freebuff(buff);
			str = ft_strdup(pos_buff);
			free(pos_buff);
			pos_buff = (NULL);
			return (str);
		}
		buff[c] = '\0';
		tmp = pos_buff;
		pos_buff = ft_strjoin(pos_buff, buff);
		free(tmp);
	}
	free(buff);
	pos_buff = cut_str(pos_buff, &str);
	return (str);
}

/*
#include <fcntl.h>
#include <stdio.h>
int main(int ac, char **av)
{
	int fd;
	int num = 118;
	int	i = 1;
	// char *str =NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0)
		return (1);

	while (num)
	// while ((str = get_next_line(fd)) != NULL)
	{
		char *str = get_next_line(fd);
		printf("=>'%s'", str);
		free(str);
		num--;
		i++;
	}
	return (0);
}
*/