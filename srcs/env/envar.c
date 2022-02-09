/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:36:58 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/02/09 22:51:12 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envar(t_env *env, char *vname)
{
	while (env && str_cmp(vname, env->name))
		env = env->next;
	if (env)
		return (env->val);
	return (NULL);
}

void	del_var(t_env **env, char *vname)
{
	t_env	*todelete;
	t_env	*current;

	current = *env;
	todelete = NULL;
	if (current && !str_cmp(current->name, vname))
	{
		*env = (*env)->next;
		todelete = current;
	}
	else
	{
		while (current->next && str_cmp(current->next->name, vname))
			current = current->next;
		if (current->next && !str_cmp(current->next->name, vname))
		{
			todelete = current->next;
			current->next = current->next->next;
		}
	}
	if (todelete)
		clear_envnode(&todelete);
}
