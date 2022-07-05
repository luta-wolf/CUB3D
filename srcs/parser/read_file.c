/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:08:53 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:08:54 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	check_file_permission(const char *file_name)
{
	int	index;
	int	perm_size;

	perm_size = (int) ft_strlen(FILE_EXTENSION);
	index = (int) ft_strlen(file_name) - perm_size;
	if (index < 0
		|| ft_strncmp(FILE_EXTENSION, &file_name[index], perm_size + 1) != 0)
		put_error(INVALID_PERMISSION, ERR_PERMISSION);
}

static char	*read_text(int fd)
{
	int		flag;
	char	buff[BUFFER_SIZE + 1];
	char	*text;
	char	*result;

	text = ft_strdup("");
	if (text == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	flag = (int) read(fd, buff, BUFFER_SIZE);
	while (*buff != END_OF_LINE && flag > 0)
	{
		buff[flag] = END_OF_LINE;
		result = ft_strjoin(text, buff);
		if (result == NULL)
			put_error(INVALID_MEMORY, ERR_MEMORY);
		free(text);
		text = result;
		flag = (int) read(fd, buff, BUFFER_SIZE);
	}
	if (flag < 0)
		put_error(INVALID_READ, ERR_READ);
	return (result);
}

char	*read_file(char *file_name)
{
	int		fd;
	char	*text;

	check_file_permission(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		put_error_and_arg(file_name, INVALID_FILE, ERR_FILE);
	text = read_text(fd);
	if (close(fd) == -1)
		put_error(INVALID_CLOSE, ERR_CLOSE);
	return (text);
}
