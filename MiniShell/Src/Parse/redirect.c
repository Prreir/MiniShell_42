/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:31 by lugoncal          #+#    #+#             */
/*   Updated: 2023/11/07 13:54:29 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

int	redirect_in(char *file, int flags)
{
	int	fd;

	fd = open(file, flags);
	if (fd == -1)
	{
		print_error(strerror(errno), 1, 0);
		g_exit_status = 1;
		return (1);
	}
	dup2(fd, IN);
	close(fd);
	return (0);
}

int	redirect_out(char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		print_error(strerror(errno), 1, 0);
		g_exit_status = 1;
		return (1);
	}
	dup2(fd, OUT);
	close(fd);
	return (0);
}

int	make_redirect(char *word, char *file, int *save, t_data *data)
{
	int	file_error;

	file_error = 0;
	if (!ft_strcmp(word, ">"))
		file_error = redirect_out(file, O_WRONLY | O_CREAT | O_TRUNC);
	else if (!ft_strcmp(word, "<"))
		file_error = redirect_in(file, O_RDONLY);
	else if (!ft_strcmp(word, ">>"))
		file_error = redirect_out(file, O_WRONLY | O_CREAT | O_APPEND);
	else if (!ft_strcmp(word, "<<"))
		file_error = heredoc(file, save, data);
	return (file_error);
}

int	check_redirect(t_token *token, t_token *cur, int *save, t_data *data)
{
	int	file_error;

	file_error = 0;
	while (token != cur)
	{
		if (!token->next)
			break ;
		if (token->type == REDIR_IN || token->type == REDIR_OUT || \
			token->type == REDIR_APPEND || token->type == HEREDOC)
		{
			if (make_redirect(token->word, token->next->word, save, data))
				file_error = 1;
			token = token->next;
		}
		token = token->next;
	}
	return (file_error);
}
