/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:57:22 by minummin          #+#    #+#             */
/*   Updated: 2020/11/28 16:57:25 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char		*ft_get_line(char *s);
char		*ft_get_rest(char *s);
int		ft_return(char **s, int ret);
int		ft_free(char **s);
int		get_next_line(int fd, char **line);

#endif
