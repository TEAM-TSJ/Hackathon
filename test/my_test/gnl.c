#include "main.h"

static int	search_newline(char *fd_content)
{
	int		yes_new;
	int		no_new;

	yes_new = -1;
	no_new = -1;
	while (fd_content[++yes_new])
	{
		if (fd_content[yes_new] == '\n')
			return (yes_new);
	}
	return (no_new);
}

static int	save_line(char **fd_content, char **line, int yes_new)
{
	char			*next_content;
	int				new_next;

	(*fd_content)[yes_new] = '\0';
	*line = ft_strdup(*fd_content);
	new_next = ft_strlen(*fd_content + yes_new + 1);
	if (!new_next)
	{
		free(*fd_content);
		*fd_content = 0;
		return (1);
	}
	next_content = ft_strdup(*fd_content + yes_new + 1);
	free(*fd_content);
	*fd_content = next_content;
	return (1);
}

static int	decide_err_eof(char **fd_adr, char **line, int rd_size)
{
	int		yes_new;

	if (rd_size < 0)
		return (-1);
	yes_new = search_newline(*fd_adr);
	if (*fd_adr && (yes_new) >= 0)
		return (save_line(fd_adr, line, yes_new));
	else if (*fd_adr && yes_new < 0)
	{
		*line = *fd_adr;
		*fd_adr = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

void	make_read_buffer_free(char *read_buffer)
{
	free(read_buffer);
	read_buffer = 0;
}

int	get_next_line(int fd, char **line)
{
	static char		*fd_content[OPEN_MAX];
	char			*read_buffer;
	int				content_size;
	int				yes_newline;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(read_buffer))
		return (-1);
	content_size = read(fd, read_buffer, BUFFER_SIZE);
	while (content_size > 0)
	{
		read_buffer[content_size] = '\0';
		fd_content[fd] = ft_strjoin(fd_content[fd], read_buffer);
		yes_newline = search_newline(fd_content[fd]);
		if (yes_newline >= 0)
		{
			make_read_buffer_free(read_buffer);
			return (save_line(&fd_content[fd], line, yes_newline));
		}
		content_size = read(fd, read_buffer, BUFFER_SIZE);
	}
	make_read_buffer_free(read_buffer);
	return (decide_err_eof(&fd_content[fd], line, content_size));
}
