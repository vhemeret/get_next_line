/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:52:11 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/05 22:57:50 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (pos_buff[i])
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

	str = NULL;
	buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || buff == NULL)
		return (NULL);
	if (!pos_buff)
		pos_buff = ft_strdup("");
	while (!ft_strchr(pos_buff, '\n'))
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c <= 0)
			break ;
		buff[c] = '\0';
		tmp = pos_buff;
		pos_buff = ft_strjoin(pos_buff, buff);
		free(tmp);
	}
	pos_buff = cut_str(pos_buff, &str);
	return (str);
}

/*#include <fcntl.h>
#include <stdio.h>
int main(int ac, char *av[])
{
	int fd;
	int num = 104;
	int	i = 1;
	// char *str =NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0)
		return (1);
	while (num)
	// while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", get_next_line(fd));
		num--;
		i++;
	}
	return (0);
}*/
