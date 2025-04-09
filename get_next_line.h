/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:18:39 by kyamada           #+#    #+#             */
/*   Updated: 2025/04/09 18:09:35 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

char				*get_next_line(int fd);
size_t				ft_strlen(const char *str);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000

# endif
#endif