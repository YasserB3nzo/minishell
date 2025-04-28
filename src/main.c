#include <readline/readline.h>
#include "../minishell.h"

int main()
{
    char *command_line;

    command_line = readline("minishell >");
    
    return 0;
}