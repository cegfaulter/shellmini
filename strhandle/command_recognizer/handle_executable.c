#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "../gnl/get_next_line.h"
#include "../split/ft_split.h"

int     is_executable(const char *file)
{
    struct stat st;

    return (stat(file, &st) == 0 && st.st_mode & S_IXUSR);
}



char    *get_command_path(const char *filename)
{
    int     fd;
    char    *line;
    char    *new_line;

    if (is_executable(filename))
    {
        fd = open(filename, O_RDONLY);
        get_next_line(fd, &line);
        if (strlen(line) < 2 || line[0] != '#' || line[1] != '!')
        {
            free(line);
            return (NULL);
        }
        new_line = malloc(sizeof(char) * (strlen(line) - 2));
        strcpy(new_line, line + 2);
        free(line);
        return (new_line);
    }
    return (NULL);
}

char    **parse_shabang(const char *filename)
{
    char    *shabang_line;

    shabang_line = get_command_path(filename);
    return ((!shabang_line) ? NULL : ft_csplit(shabang_line, ' ', NULL));
}
// execute using "gcc ../split/*.c ../gnl/*.c handle_executable.c"
int     get_shabang_length(const char **shabang)
{
    int     len;

    len = 0;
    while (shabang[len])
        len++;
    return (len);
}

char    **shabang_copy(const char **new_shabang, const char **old_shabang, const char *file)
{
    int     iter;

    iter = 0;
    while(old_shabang[iter])
    {
        new_shabang[iter] = new_shabang[iter];
        iter++;
    }
    return (new_shabang);
}

int     main(void)
{
    char *filename = "./file.py";
    char **p = parse_shabang(filename); // function return arr 2d where the command absolute path located at index zero
    char **new_p;
    if (p)
    {
        new_p = malloc(sizeof(char) * ());
        int a = execve(p[0], p, NULL);
        printf("%d\n", a);
    }
    return (0);
}