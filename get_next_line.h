/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:18:39 by kyamada           #+#    #+#             */
/*   Updated: 2025/02/11 15:53:48 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE 10

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

int					ft_search_next(char *bufp);
char				*ft_read_and_join(int fd,char *bufp);
char				*get_next_line(int fd);
size_t				ft_strlen(const char *str);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif