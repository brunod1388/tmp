/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:24:39 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/02/09 15:24:51 by bgoncalv         ###   ########.fr       */
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

static t_bool	parse_escape(t_parser *p)
{
	(void)p;
	if (p->input[p->i] != '\\')
		return (FALSE);
	p->i++;
	if (p->input[p->i] == 'n')
		p->new_str = str_add_char(p->new_str, '\n');
	else if (p->input[p->i] == 't')
		p->new_str = str_add_char(p->new_str, '\t');
	else
		p->new_str = str_add_char(p->new_str, p->input[p->i]);
	p->i++;
	return (TRUE);
}

static t_bool	parse_var(t_parser *p)
{
	char	*var_name;

	if (p->input[p->i] != '$')
		return (FALSE);
	var_name = NULL;
	p->i++;
	while (p->input[p->i])
	{
		if (p->input[p->i] == '\\')
		{
			p->i++;
			break ;
		}
		else if (!((p->input[p->i] >= 'a' && p->input[p->i] <= 'z')
				|| (p->input[p->i] >= 'A' && p->input[p->i] <= 'Z')
				|| (p->input[p->i] >= '0' && p->input[p->i] <= '9')
				|| (p->input[p->i] == '_')))
			break ;
		else
			var_name = str_add_char(var_name, p->input[p->i++]);
	}
	// TODO: get env from main(, , env), not getenv.
	p->new_str = str_add_char(p->new_str, '<');
	p->new_str = str_add_str(p->new_str, var_name);
	p->new_str = str_add_char(p->new_str, '>');
	return (TRUE);
}

static t_bool	parse_single(t_parser *p)
{
	if (p->input[p->i] != '\'')
		return (FALSE);
	p->i++;
	while (p->input[p->i])
	{
		if (p->input[p->i] == '\'')
		{
			p->i++;
			return (TRUE);
		}
		else
			p->new_str = str_add_char(p->new_str, p->input[p->i++]);
	}
	printf("unclosed single!!\n");
	safe_free((void **)&p->new_str);
	return (TRUE);
}

static t_bool	parse_double(t_parser *p)
{
	if (p->input[p->i] != '\"')
		return (FALSE);
	p->i++;
	while (p->input[p->i])
	{
		if (p->input[p->i] == '\"')
		{
			p->i++;
			return (TRUE);
		}
		else if (parse_var(p))
			continue ;
		else if (parse_escape(p))
			continue ;
		else
			p->new_str = str_add_char(p->new_str, p->input[p->i++]);
	}
	printf("unclosed double!!\n");
	safe_free((void **)&p->new_str);
	return (TRUE);
}

static t_bool	parse_whitespace(t_parser *p)
{
	if (p->input[p->i] != ' ')
		return (FALSE);
	while (p->input[p->i])
	{
		if (p->input[p->i] == ' ')
			p->i++;
		else
			return (TRUE);
	}
	printf("trailing!!");
	return (TRUE);
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