/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:19:56 by kyamada           #+#    #+#             */
/*   Updated: 2025/02/02 15:30:57 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char		buf[BUFSIZ];
	static char	*bufp;
	size_t		n;

	n = 0;
	if (n <= 0)
		return ("EOF");
	if (n == 0)
	{
		n = read(fd, buf, BUFSIZ);
		bufp = ft_strjoin(buf, "");
		return (bufp);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	static int	i = 0;
	size_t		j;

	j = i;
	str = ft_read(fd);
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
	}
	return (ft_substr(str, j, i - j));
}

int main(void) {
    int fd;

    fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return 0;
}
