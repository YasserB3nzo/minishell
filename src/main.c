#include "../minishell.h"

int g_exit_status =0;

void sigint_handler(int signo) {
    (void)signo; 
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

int main()
{

    signal(SIGINT, sigint_handler);
    char *command_line;
 
    while(1)
    {
			command_line = readline("minishell >");
            parssing(command_line) ;

    }
    return 0;
}


