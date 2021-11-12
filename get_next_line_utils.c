/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:23:12 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/04 10:15:39 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}


char *join_str(char *s1, char *s2)
{
    int        l;
    char    *s;
    int        i;
    int        p;
    
    i = 0;
    l = ft_strlen(s1) + ft_strlen(s2);
    s = (char *)malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
    while (s1 != 0 && s1[i] != '\0')
    {
        s[i] = s1[i];
        i++;
    }
    p = i;
    i = 0;
    while (s2[i] != '\0')
    {
        s[i + p] = s2[i];
        i++;
    }
    s[i + p] = '\0';
    free(s1);
    return (s);
}

int			is_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
