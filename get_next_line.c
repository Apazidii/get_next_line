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

char *get_buff(char *buff)
{
	int		i;
	char	*res;

	i = 0;
	while (buff[i])
		i++;
	if (i == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i = 0;
	while (buff[i])
	{
		res[i] = buff[i];
		i++;
	}
	return (res);
}

void buff_init(char *buff)
{
	int	i;

	i = 0;
	if (!*buff)
	{
		while (i < BUFFER_SIZE)
		{
			buff[i] = '\0';
			i++;
		}
	}
}

void	save_buff(char *save, char *buff)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (*save && *buff)
	{
		while (save[i] && save[i] != '\n')
			i++;
		if (save[i] == '\n')
		{
			i++;
			while (save[i])
			{
				buff[j] = save[i];
				i++;
				j++;
			}
			buff[j] = '\0';
		}
	}
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
	if (str[i] == '\n')
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
	char		*save;
	int				ret;
	static char		buff[BUFFER_SIZE + 1];

	save = get_buff(buff);
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
	save_buff(save, buff);
	return (get_line(save));
}





