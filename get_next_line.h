/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:40 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/02 15:39:47 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_buff
{
	char			arr[BUFFER_SIZE + 1];
	unsigned int	idc;
	int				ret;
}				t_buff;

typedef struct s_list
{
	char			arr[BUFFER_SIZE + 1];
	unsigned int	len;
	struct s_list	*next;
}	t_list;

t_list	*new_list(void);
t_list	*list_next(t_list *elem);
void	free_list_elem(t_list *elem);
void	free_list(t_list **list);
char	*get_next_line(int fd);

#endif
