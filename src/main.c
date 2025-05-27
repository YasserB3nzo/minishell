#include "../minishell.h"

int main()
{
    char *command_line;
    command_line = readline("minishell >");
 
    while(1)
    {
            if(parssing(command_line) == 1)
            {
                return 1;
            }
            else 
            {
                write(1,"khata2",6);
                return 0;
            }

    }
    return 0;
}