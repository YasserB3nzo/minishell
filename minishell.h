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
# include <term.h>
#include "./Libft/libft.h"
#include "./printf/ft_printf.h"


# include <readline/readline.h>
# include <readline/history.h>


int parssing(char *string);
int ft_echo(char **string , int flag);
int ft_cd(char  *PATH);
void free_array(char **array);


#endif