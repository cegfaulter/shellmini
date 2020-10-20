#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// int		main(void)
// {
// 	int		pid;
// 	char	*str;

// 	pid = fork();
// 	str = (char*)malloc(sizeof(char) * 10);
// 	if (pid == 0)
// 	{
// 		printf("hello");
// 		str = 0;
// 		exit(0);
// 	}
// 	else
// 	{
// 		printf("hello");
// 	}
// 	str = 0;
// 	//free(str);

// 	while (1);
// 	return (0);
// }
