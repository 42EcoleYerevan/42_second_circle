/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:48:46 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 18:41:43 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_strlen_gnl(char *str);
char	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strcat_gnl(char *dst, char *src);
char	*ft_strjoin_gnl(char *str1, char *str2);
char	*ft_strchr_gnl(char *str, char c);
char	*ft_substr_gnl(char *s, size_t start, size_t len);
char	*rebuffer(char *buffer);
char	*get_line(char *buffer);
char	*bufferjoin(char *buffer, char *str);
char	*read_line(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
