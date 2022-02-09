/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:30:29 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/09 15:18:39 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*line;

	(void)argc, (void)argv;
	while (42)
	{
		line = readline("🍆 ");
		if (line == NULL || line[0] == '\0')
			continue ;
		add_history(line);
		parse_input(line);
		//printf("%s\n", line);
		free(line);
	}
}
