/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:30:29 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/09 22:51:53 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc, (void)argv;

	// char	*line;

	// while (42)
	// {
	// 	line = readline("🍆 ");
	// 	if (line == NULL || line[0] == '\0')
	// 		continue ;
	// 	add_history(line);
	// 	parse_input(line);
	// 	//printf("%s\n", line);
	// 	free(line);
	// }

	t_env	*env;
	char	*s;
	
	env = init_env(envp);

	printf("\n\n\n\n\n\n");
	s = get_envar(env, "SHELL");
	printf("SHELL : %s\n", s);
	printf("\n\n\n\n");
	del_var(&env, "SHELL");
	// print_env(env);
	clear_env(&env);
	// while(42);
	return (0);
}
