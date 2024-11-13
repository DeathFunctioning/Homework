#ifndef	MAIN_H
#define	MAIN_H


//rl_clear_history
//rl_on_new_line
//rl_replace_line
//rl_redisplay
//add_history
// printf perror
# include <stdio.h>
// readline 
# include <readline/readline.h>
# include <readline/history.h>
// fork write access read close exit getcwd chdir unlink execve dup dup2
// pipe isatty ttyname ttyslot 
# include <unistd.h>
// malloc free getenv 
# include <stdlib.h>
// wait waitpid wait3 wait4
# include <sys/wait.h>
// open
# include <fcntl.h>
// signal sigaction sigemptyset sigaddset kill
# include <signal.h> 
// stat fstat lstat
# include <sys/stat.h>
// opendir readdir closedir
# include <dirent.h>
// ioctl
# include <sys/ioctl.h>
// tcsettar tcgettatr
# include <termios.h>
// tgetent tgetflag tgetnum tgetstr tgoto tputs
# include <curses.h>
# include <term.h>
// header for all macro defines 
# include "macros.h"



#endif
