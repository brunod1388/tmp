/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdufresn <gdufresn@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:17 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/07 15:50:53 by gdufresn         ###   ########.fr       */
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
