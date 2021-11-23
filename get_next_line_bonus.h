#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 265
# endif

typedef struct s_buff
{
	char	arr[BUFFER_SIZE + 1];
	unsigned int	idc;
	int				ret;
	//возможная проблема тут, изменить на size_t и ssize_t
}	t_buff;

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