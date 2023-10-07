#include "get_next_line.h"

static char *ft_line(char **left, int nl)
{
    char *line = NULL;
    
    if (!*left)
        return (NULL);
    line = strndup(*left, nl);
    if (!line)
        return (NULL);

    // Update left buffer
    char *temp = strdup(*left + nl + 1);
    free(*left);
    *left = temp;

    return (line);
}

char *get_next_line(int fd)
{
    static char *left = NULL;
    char buffer[BUFFER_SIZE + 1];
    int bytes;

    char *line = NULL;

    // Error handling for fd
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // Check if there's a newline in the left buffer
    int nl = ft_find_nl(left);
    if (nl > 0)
        return ft_line(&left, nl);

    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0';
        if (!left)
            left = strdup("");

        left = ft_strjoin(left, buffer);

        // Check if there's a newline in the newly read data
        nl = ft_find_nl(left);
        if (nl > 0)
            return ft_line(&left, nl);
    }

    // Reached the end of the file
    if (left)
    {
        line = strdup(left);
        free(left);
        left = NULL;
    }

    return (line);
}
/*
int     main(void)
{
        int     fd;

       fd = open("test.txt", O_RDONLY);
        if (fd == -1)
        {
                printf("Why want this file open");
                return (1);
        }
        printf("test 1 = %s", get_next_line(fd));
        printf("test 2 = %s", get_next_line(fd));
        printf("test 3 = %s", get_next_line(fd));
        printf("test 4 = %s", get_next_line(fd));
        printf("test 5 = %s", get_next_line(fd));
        printf("test 6 = %s", get_next_line(fd));
        printf("test 7 = %s", get_next_line(fd));
        printf("test 8 = %s", get_next_line(fd));
        printf("test 9 = %s", get_next_line(fd));
        printf("test 10 = %s", get_next_line(fd));
        close(fd);
        return (0);
}*/ 
