/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:34:44 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/28 15:33:12 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	tokenlen(char *input)
{
	int len;
	int	step;

	len = 0;
	step = 0;
	while (input[len] && !(is_space(input[len]) || is_special(input[len])))
	{
		if(is_quote(input[len]))
		{
			step = step_next(input);
			if (step == -1)
			{
				printf("error unclosed quote");
				return (-1);
			}
			len = len + step;
		}
		len++;
	}
	return (len);
}

char	*normal_token(t_data *data, char *input)
{
	int	len;
	
	len = tokenlen(input);
	if (len == -1)
		return (NULL);
	printf("%d\n", len);
	(void)data;
	return (input);
}

int	process(t_data *data, char *input)
{
	while (*input)
	{
		while (is_space(*input))
			input++;
		if (*input == '\0')
			break;
		if (is_special(*input))
		{
			//input = special_token(data, input);
			if (input == NULL)
				return (1);
			continue;
		}
		input = normal_token(data, input);
		if (input == NULL)
			return (1);
	}
	return (0);
}

int	input_v(t_data *data)
{
	if (!ft_strlen(data->input))
	{
		free(data->input);
		return (1);
	}
	add_history(data->input);
	if (process(data, data->input))
    {
        boom_input(data);
		return (1);
    }
    return (0);
}
