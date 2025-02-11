/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:19:56 by kyamada           #+#    #+#             */
/*   Updated: 2025/02/11 16:33:46 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search_next(char *bufp)
{
	size_t	i;

	i = 0;
	while (bufp[i] != '\0')
	{
		if (bufp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_and_join(int fd, char *bufp)
{
	char	buf[BUFSIZ];
	size_t	count;
	char	*tmp;

	while (1)
	{
		count = read(fd, buf, BUFSIZ);
		if (count <= 0)
			break ;
		buf[count] = '\0';
		tmp = ft_strjoin(bufp, buf);
//		if (bufp)
//			free(bufp);
		bufp = tmp;
		if (ft_search_next(bufp))
			break ;
	}
	return (bufp);
}

char	*get_next_line(int fd)
{
	static char	*str = "";
	char		*line;
	size_t		i;
	char		*substr;

	if (fd < 0 || BUFSIZ <= 0)
		return (NULL);
	str = ft_read_and_join(fd, str);
	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = ft_substr(str, 0, i + 1);
	substr = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	free(str);
	str = substr;
	return (line);
}

// int main(void) {
//     int fd;

//     fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
//     {
//         perror("Failed to open file");
//         return (1);
//     }
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return 0;
// }
