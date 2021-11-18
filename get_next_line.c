#include "get_next_line.h"

static void	init_res(t_result *res)
{
	res->arr = NULL;
	res->size = 0;
}

static int	copy_buff_to_list_elem(t_buff *buff, t_list *list, int *res)
{
	int	is_line_end;

	is_line_end = 0;
	while ((buff->readed_left > 0) && (buff->arr[buff->next_char_idx] != '\n'))
	{
		list->arr[list->len++] = buff->arr[buff->next_char_idx++];
		buff->readed_left--;
		*res = *res + 1;
	}
	if ((buff->readed_left > 0)
				&& (buff->arr[buff->next_char_idx] == '\n'))
	{
		is_line_end = 1;
		list->arr[list->len++] = buff->arr[buff->next_char_idx++];
		*res = *res + 1;
		buff->readed_left--;
	}
	if (buff->readed_left == 0)
		buff->next_char_idx = 0;
	return (is_line_end);
}

static t_list	*line_to_list(t_buff *buff, t_list *list, int *res, int fd)
{
	if (copy_buff_to_list_elem(buff, list, res))
		return (list);
	buff->readed_left = read(fd, buff->arr, BUFFER_SIZE);
	while (buff->readed_left > 0)
	{
		list = push_back_list(list);
		if (!list)
			return (NULL);
		if (copy_buff_to_list_elem(buff, list, res))
			return (list);
		buff->readed_left = read(fd, buff->arr, BUFFER_SIZE);
	}
	if (buff->readed_left == -1)
	{
		buff->readed_left = 0;
		return (NULL);
	}
	return (list);
}

static char	*list_to_str(t_list *list, char **res, int res_size)
{
	size_t	str_idx;
	size_t	list_elem_idx;

	if (res_size == 0)
		return (NULL);
	*res = (char *)malloc(sizeof(char) * (res_size + 1));
	if (!*res)
		return (NULL);
	str_idx = 0;
	while (list != NULL)
	{
		list_elem_idx = 0;
		while (list_elem_idx < list->len)
			(*res)[str_idx++] = list->arr[list_elem_idx++];
		list = list->next;
	}
	(*res)[res_size] = '\0';
	return (*res);
}

char	*get_next_line(int fd)
{
	static t_buff	buffs[OPEN_MAX];
	t_list			*list;
	char			*res;
	int				res_size;

	res_size = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	list = new_list();
	if (!list)
		return (NULL);
	if (!line_to_list(&buffs[fd], list, &res_size, fd))
	{
		free_list(&list);
		return (NULL);
	}
	list_to_str(list, &res, res_size);
	free_list(&list);
	return (res);
}
