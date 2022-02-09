/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:32:52 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/09 15:18:39 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	return (len);
}

char *str_dup(char *str)
{
	int		len;
	int		i;
	char	*mem;

	len = str_len(str);
	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	i = -1;
	while (++i < len)
		mem[i] = str[i];
	return (mem);
}

char	*str_add_char(char *str, char c)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	len = str_len(str);
	new = malloc(len + 1 + 1);
	if (!new)
		return (NULL);
	j = 0;
	i = 0;
	while (str && i < len)
		new[j++] = str[i++];
	new[i] = c;
	new[i + 1] = '\0';
	safe_free((void **)&str);
	return (new);
}

/*
char	*str_add_chars(char *a, char *b, int count)
{
	int		i;
	int		j;
	int		len_a;
	char	*new;

	len_a = str_len(a);
	new = malloc(len_a + count + 1);
	if (!new)
		return (NULL);
	j = 0;
	i = 0;
	while (a && i < len_a)
		new[j++] = a[i++];
	i = 0;
	while (b && i < count)
		new[j++] = b[i++];
	new[j] = '\0';
	safe_free((void **)&a);
	return (new);
}
*/

char	*str_add_str(char *a, char *b)
{
	int		i;
	int		j;
	int		len_a;
	int		len_b;
	char	*new;

	len_a = str_len(a);
	len_b = str_len(b);
	new = malloc(len_a + len_b + 1);
	if (!new)
		return (NULL);
	j = 0;
	i = 0;
	while (a && i < len_a)
		new[j++] = a[i++];
	i = 0;
	while (b && i < len_b)
		new[j++] = b[i++];
	new[j] = '\0';
	safe_free((void **)&a);
	safe_free((void **)&b);
	return (new);
}
