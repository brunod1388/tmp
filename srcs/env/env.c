/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:21:40 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/02/09 22:53:54 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*str_to_envnode(char *s)
{
	t_env	*env;
	int		l;

	if (!s)
		return (NULL);
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	l = 0;
	while (s[l] && s[l] != '=')
		l++;
	env->name = str_ndup(s, l++);
	env->val = str_ndup(&s[l], str_len(s) - l);
	env->next = NULL;
	if (!env->name || !env->val)
		clear_envnode(&env);
	return (env);
}

static t_env	*add_envnode(t_env *env, char *s)
{
	t_env	*current;

	if (!env)
		return (str_to_envnode(s));
	current = env;
	while (current->next)
		current = current->next;
	current->next = str_to_envnode(s);
	return (env);
}

t_env	*init_env(char **envp)
{
	t_env	*env;
	int		i;

	env = NULL;
	i = 0;
	while (envp[i])
		env = add_envnode(env, envp[i++]);
	return (env);
}

void	clear_env(t_env **env)
{
	t_env	*tmp;

	while (*env)
	{
		tmp = (*env);
		*env = (*env)->next;
		clear_envnode(&tmp);
	}
}

void	clear_envnode(t_env **node)
{
	safe_free((void **) &(*node)->name);
	safe_free((void **) &(*node)->val);
	safe_free((void **) node);
}
