#include "../../minishell.h"


int ft_echo(char *string)
{
    write(2,string,ft_strlen(string));
    return 1;
}
// void cd(char *path)
// {
//      chdir(getenv("HOME"));
// }