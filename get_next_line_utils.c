/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:51:59 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/28 18:51:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copystr(char *nws, const char *s1, const char *s2, unsigned int len)
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

char	*ft_strjoin(const char *s1, const char *s2)
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