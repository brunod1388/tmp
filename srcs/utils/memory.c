/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:17 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/09 17:17:32 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*malloc_zero(size_t size)
{
	size_t	i;
	void	*memory;

	memory = malloc(size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < size)
		((unsigned char *)memory)[i++] = 0;
	return (memory);
}

void	safe_free(void **memory)
{
	if (*memory)
		free(*memory);
	*memory = NULL;
}
