/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:22:59 by lugoncal          #+#    #+#             */
/*   Updated: 2023/10/17 14:05:45 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern int	g_exit_status;

void	input_update(void)
{
	int	tmp;

	tmp = open(HEREDOC_FILE, O_RDONLY);
	unlink(HEREDOC_FILE);
	dup2(tmp, STDIN_FILENO);
	close(tmp);
}

void	tmp_clear(void)
{
	int	tmp;

	tmp = open(HEREDOC_FILE, O_WRONLY | O_TRUNC, 0644);
	close(tmp);
}

void	heredoc_input(int tmp, char *file, t_data *data)
{
	char	*input;
	char	delimiter[10000];

	boom(data);
	file_heap(file, delimiter);
	signal(SIGINT, handle_heredoc_ctrl_c);
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			print_error("warning: here-document delimited by end-of-file", 0);
			close(tmp);
			exit(EXIT_SUCCESS);
		}
		if (ft_strcmp(input, delimiter) != 0)
			ft_putendl_fd(input, tmp);
		else
			break ;
		free(input);
	}
	close(tmp);
	free(input);
	exit(g_exit_status);
}

int	tmp_create(void)
{
	int	fd;

	fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error(strerror(errno), 1);
	return (fd);
}

int	heredoc(char *file, int *save, t_data *data)
{
	int	tmp;
	int	save_out;
	int	pid;
	int	status;

	(void)data;
	tmp = tmp_create();
	if (tmp == -1)
		return (1);
	save_out = dup(STDOUT_FILENO);
	dup2(save[OUT], STDOUT_FILENO);
	dup2(save[IN], STDIN_FILENO);
	pid = fork();
	if (pid == 0)
		heredoc_input(tmp, ft_strdup(file), data);
	wait_and_update_main_signals(pid, &status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		tmp_clear();
		g_exit_status = 130;
	}
	input_update();
	dup2(save_out, STDOUT_FILENO);
	close(save_out);
	return (0);
}
