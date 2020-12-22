#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"

int     is_executable(const char *file)
{
    struct stat st;

    return (stat(file, &st) == 0 && st.st_mode & S_IXUSR);
}

char    *replace(char *str, char old, char *new)
{
    int     iter;
    int     current_iter;
    int     is_space;
    char    *new_str;

    iter = 0;
    while (str[iter])
    {
        if (str[iter] == ' ' && !is_space)
        {
            new_str[current_iter] = '/';
            is_space = 1;
            current_iter++;
        }
        else if (str[iter] == '/')
            is_space = 1;
        else if (is_space && str[iter] == ' ')
        {
            while (str[iter + 1])
            {
                if (str[iter] == ' ')
                    iter++;
            }
            is_space = 0;
        }
        else
        {

        }
    }
}
char    *get_command_path(const char *filename)
{
    int     fd;
    char    *line;
    char    *new_line;

    if (is_executable(filename))
    {
        fd = open(filename, O_WRONLY);
        line = get_next_line(fd, &line);
        if (line[0] != '#' || line[1] != '!')
        {
            free(line);
            return (NULL);
        }
        strcpy(new_line, line + 2);
        free(line);
        return (new_line);
    }
    return (NULL);
}

int     main(void)
{
    return (0);
}