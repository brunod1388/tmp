/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:19:06 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/02/09 22:53:20 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n", env->name, env->val);
		// printf("varname : |%s|, varval : |%s|\n", env->name, env->val);
		env = env->next;
	}
}
