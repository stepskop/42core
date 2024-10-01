/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:33:35 by username          #+#    #+#             */
/*   Updated: 2024/10/01 19:22:36 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s);
	ptr = malloc((str_len * sizeof(char)) + 1);
	if (!ptr)
		return (ptr);
	ptr[str_len] = '\0';
	while (str_len-- > 0)
		ptr[str_len] = s[str_len];
	return (ptr);
}

char    *get_next_line(int fd)
{
    static char *str[MAX_FD];
    char        buf[BUFFER_SIZE + 1];
    char        *line;
    size_t      size;
    size_t      nlen;
    char        *tmp;
    char        *new_str;

    size = 1;
    if (fd < 0)
        return (NULL);
    while (size > 0)
    {
        size = read(fd, buf, BUFFER_SIZE);
        buf[size] = '\0';    
        if (!str[fd])
            str[fd] = ft_strdup("");
        tmp = str[fd];
        str[fd] = ft_strjoin(tmp, buf);
        free(tmp);
        if (ft_memchr(buf, '\n', size))
            break ;
    }
    if (size == 0 && (!str[fd] || !str[fd][0]))
    {
        free(str[fd]);
        str[fd] = NULL;
        return (NULL);
    } 
    nlen = 0;
    while (str[fd][nlen] && str[fd][nlen] != '\n')
        nlen++;
    line = ft_substr(str[fd], 0, nlen);
	new_str = ft_strdup(str[fd] + nlen + 1);
	free(str[fd]);
	str[fd] = new_str;
	return (line);  // Return the extracted line
}

// int main()
// {
// 	char *a, *b;
// 	int fd = open("file.txt", O_RDONLY);
// 	a = get_next_line(fd);
// 	b = get_next_line(fd);
// 	// if (fd == -1)
// 	// 	return 1;
// 	printf("1: %s\n", a);
// 	printf("2: %s\n", b);
// 	free(a);
// 	free(b);
// 	// printf("%s", get_next_line(fd));
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// }
