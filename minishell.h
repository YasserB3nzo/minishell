#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>      
# include <stdlib.h>     
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h> 
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
#include "./libft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>


# include <readline/readline.h>
# include <readline/history.h>

int parssing(char *string);
void exits();
void	pwd(char **args);

#endif
