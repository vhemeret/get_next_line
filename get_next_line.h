/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:52:14 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/28 18:51:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
char	*copystr(char *nws, const char *s1, const char *s2, unsigned int len);
char	*ft_strjoin(const char *s1, const char *s2);

#endif