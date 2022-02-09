/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:24:39 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/02/09 17:20:21 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Do operators.

static void	add_string(t_parser *p)
{
	if (p->new_str)
	{
		// printf("%s\n", p->new_str);
		p->result = str_list_add(p->result, p->new_str);
		p->new_str = NULL;
	}
}

static void	parse_normal(t_parser *p)
{
	while (p->input[p->i])
	{
		if (parse_double(p))
			continue ;
		else if (parse_single(p))
			continue ;
		else if (parse_var(p))
			continue ;
		else if (parse_escape(p))
			continue ;
		else if (parse_whitespace(p))
		{
			add_string(p);
			continue ;
		}
		else
			p->new_str = str_add_char(p->new_str, p->input[p->i++]);
	}
	add_string(p);
}

t_str_list	*parse_input(char *input)
{
	t_parser	parser;
	t_str_list	*str;

	parser = (t_parser){0};
	parser.input = input;
	parse_normal(&parser);

	str = parser.result;
	while (str)
	{
		printf("result: '%s'\n", str->str);
		str = str->next;
	}
	str_list_free(parser.result);
	printf("\n");
	return (NULL);
}
