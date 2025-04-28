# Minishell - Allowed Functions
This README provides a short description of each system call and library function allowed for the Minishell project.

### 1. readline

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char *readline(const char *prompt);
Reads a line from the terminal with a given prompt and returns it as a string.

Note: readline() can cause memory leaks. You are not required to fix them.

### 2. rl_clear_history

void rl_clear_history(void);
Clears the readline history list, freeing all memory associated with it.

### 3. rl_on_new_line

int rl_on_new_line(void);
Prepares readline to display a new line.

### 4. rl_replace_line

int rl_replace_line(const char *text, int clear_undo);
Replaces the contents of the input buffer with a new line of text.

### 5. rl_redisplay

void rl_redisplay(void);
Refreshes and redisplays the current input line.

### 6. add_history

void add_history(const char *line);
Adds a line to the history list, used later for navigation with arrow keys.

### 7. printf

#include <stdio.h>

int printf(const char *format, ...);
Formats and prints output to the standard output.

### 8. malloc

#include <stdlib.h>

void *malloc(size_t size);
Allocates memory dynamically.

### 9. free

#include <stdlib.h>

void free(void *ptr);
Frees dynamically allocated memory.

### 10. write

#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
Writes data to a file descriptor.

### 11. access

#include <unistd.h>

int access(const char *pathname, int mode);
Checks file accessibility (existence, permissions).

### 12. open

#include <fcntl.h>

int open(const char *pathname, int flags, ...);
Opens a file and returns a file descriptor.

### 13. read

#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
Reads data from a file descriptor.

### 14. close

#include <unistd.h>

int close(int fd);
Closes a file descriptor.

### 15. fork

#include <unistd.h>

pid_t fork(void);
Creates a new child process.

### 16. wait / waitpid / wait3 / wait4

#include <sys/wait.h>

pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
pid_t wait3(int *wstatus, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
Waits for a child process to change state.

### 17. signal

#include <signal.h>

void (*signal(int sig, void (*handler)(int)))(int);
Sets a function to handle a specific signal.

### 18. sigaction

#include <signal.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
Manages signal handling with more control than signal().

### 19. sigemptyset

#include <signal.h>

int sigemptyset(sigset_t *set);
Initializes an empty signal set.

### 20. sigaddset

#include <signal.h>

int sigaddset(sigset_t *set, int signum);
Adds a signal to a signal set.

### 21. kill

#include <signal.h>

int kill(pid_t pid, int sig);
Sends a signal to a process.

### 22. exit

#include <stdlib.h>

void exit(int status);
Terminates the calling process with an exit status.

### 23. getcwd

#include <unistd.h>

char *getcwd(char *buf, size_t size);
Gets the current working directory.

### 24. chdir

#include <unistd.h>

int chdir(const char *path);
Changes the current working directory.

### 25. stat / lstat / fstat

#include <sys/stat.h>

int stat(const char *pathname, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
Retrieves information about a file.

### 26. unlink

#include <unistd.h>

int unlink(const char *pathname);
Deletes a name and possibly the file it refers to.

### 27. execve

#include <unistd.h>

int execve(const char *pathname, char *const argv[], char *const envp[]);
Executes a program, replacing the current process.

### 28. dup / dup2

#include <unistd.h>

int dup(int oldfd);
int dup2(int oldfd, int newfd);
Duplicates a file descriptor.

### 29. pipe

#include <unistd.h>

int pipe(int pipefd[2]);
Creates a unidirectional data channel (pipe).

### 30. opendir / readdir / closedir

#include <dirent.h>

DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
Functions to open, read, and close directories.

### 31. strerror / perror

#include <string.h>

char *strerror(int errnum);

#include <stdio.h>

void perror(const char *s);
Converts an error code to a message (strerror) or prints a description of the last error (perror).

### 32. isatty

#include <unistd.h>

int isatty(int fd);
Checks if a file descriptor refers to a terminal.

### 33. ttyname

#include <unistd.h>

char *ttyname(int fd);
Returns the name of the terminal associated with a file descriptor.

### 34. ttyslot

#include <unistd.h>

int ttyslot(void);
Returns the index of the current terminal in /etc/ttys.

### 35. ioctl

#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);
Controls device parameters.

### 36. getenv

#include <stdlib.h>

char *getenv(const char *name);
Retrieves the value of an environment variable.

### 37. tcsetattr / tcgetattr

#include <termios.h>

int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
int tcgetattr(int fd, struct termios *termios_p);
Gets or sets terminal attributes.

### 38. tgetent / tgetflag / tgetnum / tgetstr / tgoto / tputs

#include <curses.h>
#include <term.h>

int tgetent(char *bp, const char *name);
int tgetflag(char *id);
int tgetnum(char *id);
char *tgetstr(char *id, char **area);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));
Low-level functions for terminal capabilities handling.


