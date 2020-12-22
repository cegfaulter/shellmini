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
int     main(void)
{
    char *filename = "./file.sh";
    char **p = parse_shabang(filename); // function return arr 2d where the command absolute path located at index zero

    if (p)
    {
        int a = execvp(filename, p);
        printf("%d\n", a);
    }
    return (0);
}