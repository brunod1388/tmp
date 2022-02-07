/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdufresn <gdufresn@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:01:00 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/07 15:53:19 by gdufresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_str_list	*str_list_last(t_str_list *list)
{
	while (list && list->next != NULL)
		list = list->next;
	return (list);
}

t_str_list	*str_list_add(t_str_list *list, char *new_str)
{
	t_str_list	*new;

	new = malloc(sizeof(t_str_list));
	if (!new)
		return (list);
	*new = (t_str_list){0};
	new->str = new_str;
	if (list)
		str_list_last(list)->next = new;
	else
		list = new;
	return (list);
}

void	str_list_free(t_str_list *list)
{
	if (list && list->next)
		str_list_free(list->next);
	safe_free((void **)&list->str);
	safe_free((void **)&list);
}
