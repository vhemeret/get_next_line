/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:52:14 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/06 13:13:33 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
char    *copystr(char *nws, char *s1, char *s2, unsigned int len);
char    *ft_strjoin( char *s1,  char *s2);
char    *ft_strchr(char *s, int c);
char    *ft_strdup( char *s);
size_t  ft_strlen(char *s);
char    *ft_substr(char  *s, unsigned int start, size_t len);

#endif
