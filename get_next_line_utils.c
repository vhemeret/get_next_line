/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:51:59 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/30 02:01:31 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copystr(char *nws,  char *s1,  char *s2, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < ft_strlen(s1))
		nws[i] = s1[i];
	i -= 1;
	j = 0;
	while (++i < len)
		nws[i] = s2[j++];
	nws[i] = '\0';
	return (nws);
}

char	*ft_strjoin( char *s1,  char *s2)
{
	char            *nws;
	unsigned int    len;

	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	nws = malloc(sizeof(char) * (len + 1));
	if (!nws)
		return (NULL);
	nws = copystr(nws, s1, s2, len);
	return (nws);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (++i <= ft_strlen(s))
		if (str[i] == (char)c)
			return (&str[i]);
	return (NULL);
}

char	*ft_strdup( char *s)
{
	size_t	s_len;
	size_t	i;
	char	*dst;

	s_len = ft_strlen(s);
	dst = malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (s[++i])
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}


size_t	ft_strlen( char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	else if (!s)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (i < len && s[start])
		{
			dest[i] = s[start];
			start++;
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}


