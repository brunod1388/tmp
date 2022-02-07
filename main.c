/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdufresn <gdufresn@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:30:29 by gdufresn          #+#    #+#             */
/*   Updated: 2022/02/07 15:51:57 by gdufresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_string(t_parser *p)
{
	if (p->new_str)
	{
		// printf("%s\n", p->new_str);
		p->result = str_list_add(p->result, p->new_str);
		p->new_str = NULL;
	}
}

static void	parse_excape(t_parser *p)
{
	(void)p;
	// TODO: skip the backslash and concat the character 
}

static void	parse_var(t_parser *p)
{
	// TODO: temporarely concat chars until next non-alphanum character
	// concat the value of the $VAR
	char	*var_name;

	var_name = NULL;
	if (p->input[p->i] == '$')
		p->i++;
	while (p->input[p->i])
	{
		if (!((p->input[p->i] >= 'a' && p->input[p->i] <= 'z')
			|| (p->input[p->i] >= 'A' && p->input[p->i] <= 'Z')
			|| (p->input[p->i] >= '0' && p->input[p->i] <= '9')
			|| (p->input[p->i] == '_')))
		{
			break ;
		}
		else
		{
			var_name = str_add_char(var_name, p->input[p->i]);
			p->i++;
		}
	}
	p->new_str = str_add_char(p->new_str, '<');
	p->new_str = str_add_str(p->new_str, var_name);
	p->new_str = str_add_char(p->new_str, '>');
	// TODO: get the thing from the ENV and put that in the new_str
}

static void	parse_single(t_parser *p)
{
	// TODO: concat chars until the next 'single'

	if (p->input[p->i] == '\'')
		p->i++;
	while (p->input[p->i])
	{
		if (p->input[p->i] == '\'')
		{
			p->i++;
			return ;
		}
		else
		{
			p->new_str = str_add_char(p->new_str, p->input[p->i]);
			p->i++;
		}
	}
	printf("unclosed single!!\n");
	safe_free((void **)&p->new_str);
	p->new_str = NULL;
}

static void	parse_double(t_parser *p)
{
	// TODO: concat chars, expand $VARS and \escapes until next "double".

	if (p->input[p->i] == '\"')
		p->i++;
	while (p->input[p->i])
	{
		if (p->input[p->i] == '\"')
		{
			p->i++;
			return ;
		}
		else if (p->input[p->i] == '$')
			parse_var(p);
		else
			p->new_str = str_add_char(p->new_str, p->input[p->i++]);
	}
	printf("unclosed double!!\n");
	safe_free((void **)&p->new_str);
	p->new_str = NULL;
}

static void	parse_whitespace(t_parser *p)
{
	// TODO: skip whitespace

	while (p->input[p->i])
	{
		if (p->input[p->i] == ' ')
			p->i++;
		else
			return ;
	}
	printf("trailing!!");
}

static void	parse_normal(t_parser *p)
{
	// TODO: concat chars, expand $VARS and \escapes until whitespace.
	// if a "double" or a 'single' appears, call the corresponding function.

	while (p->input[p->i])
	{
		if (p->input[p->i] == '\"')
			parse_double(p);
		else if (p->input[p->i]  == '\'')
			parse_single(p);
		else if (p->input[p->i] == '$')
			parse_var(p);
		else if (p->input[p->i] == ' ')
		{
			add_string(p);
			parse_whitespace(p);
		}
		else
			p->new_str = str_add_char(p->new_str, p->input[p->i++]);
	}
	add_string(p);
}

static t_str_list	*parse_input(char *input)
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

int	main(int argc, char **argv)
{
	char	*line;

	(void)argc, (void)argv;
	while (42)
	{
		line = readline("🍆 ");
		if (line == NULL || line[0] == '\0')
			continue ;
		add_history(line);
		parse_input(line);
		//printf("%s\n", line);
		free(line);
	}
}
