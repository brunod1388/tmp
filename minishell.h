/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdufresn <gdufresn@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:30:27 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/07 17:27:37 by gdufresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// DON'T KNOW: # include <readline/history.h>
// DON'T KNOW: rl_clear_history rl_on_new_line rl_replace_line rl_redisplay
// DON'T KNOW: tcsetattr tcgetattr tgetent tgetflag tgetnum tgetstr tgoto tputs

# include <readline/readline.h> /* readline add_history */
# include <stdio.h> /* printf perror */
# include <stdlib.h> /* malloc free exit getenv */
# include <unistd.h> /* write access read close
						fork getcwd chdir unlink execve
						dup dup2 pipe isatty ttyname ttyslot */
# include <fcntl.h> /* open */
# include <sys/wait.h> /* wait waitpid wait3 wait4 */
# include <signal.h> /* signal sigaction kill */
# include <sys/stat.h> /* stat lstat fstat */
# include <dirent.h> /* opendir readdir closedir */
# include <string.h> /* strerror */
# include <sys/ioctl.h> /* ioctl */

/*
 * Cool infos:
 * https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html
 * #Shell-Operation
*/

#define TRUE 1
#define FALSE 0

typedef unsigned char	t_bool;

typedef enum e_type
{
	T_TEXT = 0,
	T_OPERATOR,
}	t_type;

typedef struct s_str_list
{
	t_type				type;
	char				*str;
	struct s_str_list	*next;
}	t_str_list;

typedef struct s_parser
{
	t_str_list	*result;
	char		*new_str;
	int			i;
	char		*input;
}	t_parser;

/* memory.c */
void		*malloc_zero(size_t size);
void		safe_free(void **memory);

/* strings.c */
int			str_len(char *str);
char		*str_dup(char *str);
char		*str_add_char(char *str, char c);
// char		*str_add_chars(char *a, char *b, int count);
char		*str_add_str(char *a, char *b);

/* str_list.c */
t_str_list	*str_list_last(t_str_list *list);
t_str_list	*str_list_add(t_str_list *list, char *new_str);
void		str_list_free(t_str_list *list);

#endif
