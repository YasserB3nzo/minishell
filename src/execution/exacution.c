#include "../../minishell.h"


int ft_echo(char **string, int flag) {
    int i = 1;
    int nl = 1;

    if (!string) {
        return 1;
    }

    if (flag == 2)
    {
        i++;
        nl = 0;
    }
    while (string[i] != NULL)
    {
        write(1, string[i], strlen(string[i]));
        i++;
        if (string[i] != NULL) {
            write(1, " ", 1);
        }
    }
    if (nl) {
        write(1, "\n", 1);
    }

    return 1;
}

int ft_cd(char *path)
{
    // write(1,"---->",5);
    const char *test = getenv("PATH");
    // chdir(getenv("HOME"));
    write(1,test,ft_strlen(test));
    return 1;
}
// int chdir(const char *path);
// char *getenv(const char *name);

// $ echo "hello" > a
// $ cat a
// hello
// $ echo -n "hello" > a 
// $ cat a
// hello$            # the new line is not present, so the prompt follows last line
