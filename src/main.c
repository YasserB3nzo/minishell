#include "../minishell.h"

int main()
{
    char *command_line;

    command_line = readline("minishell >");
    
    if( parssing(command_line) )
    {
        printf("gooooooooood");
    }
    else
        printf("bbbbbbbbbbbbad");

    return 0;
}