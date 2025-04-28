#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>      // printf, perror
# include <stdlib.h>     // malloc, free, exit, getenv
# include <unistd.h>     // write, read, access, dup, dup2, fork, execve, pipe, close, isatty, ttyname, ttyslot, chdir, getcwd, unlink
# include <string.h>     // strerror
# include <fcntl.h>      // open
# include <sys/wait.h>   // wait, waitpid, wait3, wait4
# include <sys/types.h>  // types for system calls
# include <sys/stat.h>   // stat, lstat, fstat
# include <dirent.h>     // opendir, readdir, closedir
# include <signal.h>     // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/ioctl.h>  // ioctl
# include <termios.h>    // tcsetattr, tcgetattr
# include <curses.h>     // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <term.h>       // terminal capabilities functions


# include <readline/readline.h>  // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
# include <readline/history.h>   // add_history

#endif