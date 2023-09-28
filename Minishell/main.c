/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal < lugoncal@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:07:52 by lugoncal          #+#    #+#             */
/*   Updated: 2023/09/19 11:31:08 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void init(t_data *data)
{
    data->env = NULL;
}

int main(int argc, char **argv, char **env)
{
    t_data data;

    (void)argc;
    (void)argv;

    init(&data);
    env_birth(&data, env);
    return (0);
}