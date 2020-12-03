/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:02:33 by minummin          #+#    #+#             */
/*   Updated: 2020/11/28 17:02:37 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strchr(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_get_line(char *s)
{
	char	*str;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
		str[len] = s[len];
	return (str);
}

char	*ft_get_rest(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	if (!(str = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 4096)
		return (-1);
	ret = 1;
	while (ret > 0 && !ft_strchr(str[fd]))
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
	}
	*line = ft_get_line(str[fd]);
	str[fd] = ft_get_rest(str[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
