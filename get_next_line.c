/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:20:38 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/04 10:24:41 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (NULL);
	rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!rtn)
		return (NULL);
	rtn[j] = '\0';
	i++;
	while (save[i])
	{
		rtn[j] = save[i];
		i++;
		j++;
	}
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	if (str[i])
		rtn[i] = '\n';
	if (str[i])
		i++;
	rtn[i] = '\0';
	free(str);
	return (rtn);
}

char *get_next_line(int fd)
{
	static char		*save;
	char 			*save2;
	int				ret;
	char			buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE);
	while (!is_nl(save) && ret != 0)
	{
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		save = join_str(save, buff);
		if (!save)
			return (NULL);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	save2 = save;
	save = get_save(save);
	if (save == NULL)
		return (NULL);
	return (get_line(save2));
}
