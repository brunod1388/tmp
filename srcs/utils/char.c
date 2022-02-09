/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:40:12 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/02/09 17:51:15 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isaupper(char c)
{
	return ('A' <= c && c <= 'Z');
}

t_bool	ft_isalower(char c)
{
	return ('a' <= c && c <= 'z');
}

t_bool	ft_isnumeric(char c)
{
	return ('0' <= c && c <= '9');
}

t_bool	ft_isalpha(char c)
{
	return (ft_isalower(c) || ft_isaupper(c));
}

t_bool	ft_islphanum(char c)
{
	return (ft_isalower(c) || ft_isaupper(c) || ft_isnumeric(c));
}
