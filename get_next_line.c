/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:52:11 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/28 18:51:01 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd)
{
    char *res;
    static char buff[BUFFER_SIZE];

    res = malloc(sizeof(*res) * (BUFFER_SIZE + 1));
    if (res == NULL)
        return (NULL);
    
}

int main(void)
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    return (0);
}