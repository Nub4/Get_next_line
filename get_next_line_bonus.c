/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:02:33 by minummin          #+#    #+#             */
/*   Updated: 2021/01/09 10:32:15 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src || (dst == NULL && src == NULL))
		return (NULL);
	if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	i;
	int	j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	ft_memmove(str, s1, i);
	ft_memmove(str + i, s2, j);
	str[i + j] = '\0';
	free(s1);
	return (str);
}

static char	*ft_strchr(const char *s, int c)
{
	char *str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
		return (str);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char            buff[33];
	int                     ret;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	while (ret > 0 && !ft_strchr(str[fd], '\n'))
	{
		if ((ret = read(fd, buff, 32)) == -1)
			return (ft_free(&str[fd]));
		buff[ret] = '\0';
		if (!(str[fd] = ft_strjoin(str[fd], buff)))
			return (ft_free(&str[fd]));
	}
	if (!(*line = ft_get_line(str[fd])))
		return (ft_free(&str[fd]));
	if (!(str[fd] = ft_get_rest(str[fd])))
	{
		free(*line);
		return (ft_free(&str[fd]));
	}
	return (ft_return(&str[fd], ret));
}
