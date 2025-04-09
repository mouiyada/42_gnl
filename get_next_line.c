/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:19:56 by kyamada           #+#    #+#             */
/*   Updated: 2025/04/09 19:12:42 by kyamada          ###   ########.fr       */
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
	char	buf[BUFFER_SIZE + 1];
	ssize_t	count;
	char	*tmp;

	while (1)
	{
		if (ft_search_next(bufp))
			break ;
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
		{
			free(bufp);
			return (NULL);
		}
		if (count == 0)
			break ;
		buf[count] = '\0';
		tmp = ft_strjoin(bufp, buf);
		free(bufp);
		if (!tmp)
			return (NULL);
		bufp = tmp;
	}
	return (bufp);
}

char	*ft_extract_line(char **str)
{
	char	*line;
	char	*new_str;
	size_t	i;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	line = ft_substr(*str, 0, i + 1);
	if (!line)
		return (NULL);
	new_str = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
	free(*str);
	*str = new_str;
	if (!new_str)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
	}
	str = ft_read_and_join(fd, str);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_extract_line(&str);
	if (!line)
	{
		free(str);
		str = NULL;
	}
	return (line);
}
int	main(int argc, char **argv)
{
	int		fd;
	char	*s;

	(void)argc;
	(void)argv;
	fd = open(argv[1], O_RDONLY);
	// fd = 0;
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
		{
			printf("%s\n", s);
			break ;
		}
		printf("%s", s);
		free(s);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
		{
			printf("%s\n", s);
			break ;
		}
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}