#include "head.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int is_nl(char *s)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char *str_add(char *s1, char *s2)
{
    int        l;
    char    *s;
    int        i;
    int        p;
    
    i = 0;
    l = ft_strlen(s1) + ft_strlen(s2);
    s = (char *)malloc(sizeof(char) * l + 1);
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

char    *after_nl(char *s)
{
    int        i;
    int        k;
    char    *res;

    i = 0;
    while (s[i] != '\n')
        i++;
    i++;
    res = (char *)malloc(sizeof(char) * (ft_strlen(s) - i) + 1);
    res[i] = '\0';
    k = i;
    while (s[i] != '\0')
    {
        res[i - k] = s[i];
        i++;
    }
    return (res);
}

char	*before_nl(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i] = '\0';
	i = 0;
	while (s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	static char	*res;
	int			ret;
	char		*res2;

	ret = read(fd, buff, BUFFER_SIZE);
	while (!is_nl(res) && ret)
	{
		buff[ret] = '\0';
		res = str_add(res, buff);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	res2 = before_nl(res);
	res = after_nl(res);
	return (res2);
}