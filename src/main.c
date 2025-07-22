// #include "../minishell.h"

// int main()
// {
//     char *command_line;
//     command_line = readline("minishell >");

//     while(1)
//     {
//             if(parssing(command_line) == 1)
//             {
//                 return (1);
//             }
//             else
//             {
//                 write(1,"khata2",6);
//                 return (0);
//             }

//     }
//     return (0);
// }

#include "../minishell.h"
#include <readline/history.h>

int		g_exit_status = 0;
//test:ctrl +c
void	sigint_handler(int signo)
{
	(void)signo;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
//test: ctrl + \ .
void	ignore_sigquit(void)
{
	struct sigaction	sq;

	ft_memset(&sq, 0, sizeof(sq));
	sq.sa_handler = SIG_IGN;
	sigemptyset(&sq.sa_mask);
	if (sigaction(SIGQUIT, &sq, NULL))
	{
		perror("minishell: sigaction for SIGQUIT interactive failed");
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*command_line;

	ignore_sigquit();
	signal(SIGINT, sigint_handler);
	while (1)
	{
		command_line = readline("minishell >");
		if (!command_line)
			return (1);
		parssing(command_line);
		if (*command_line)
			add_history(command_line);
		free(command_line);
	}
	return (0);
}
