/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:59:06 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/19 13:59:06 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
// #include "./printf/ft_printf.h"
#include <limits.h>


# include <readline/readline.h>
# include <readline/history.h>

static int	check_overflow(int m);
int	ft_atoi(const char *str);
int parssing(char *string);
int ft_echo(char **string , int flag);
int ft_cd(char  *PATH);
void exits(char **comands);
void	pwd(char **args);
void free_array(char **array);
int exec(char **args, char *command);


#endif