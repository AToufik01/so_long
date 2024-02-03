/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:54:12 by ataoufik          #+#    #+#             */
/*   Updated: 2024/01/31 23:57:33 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file(char *str, char *find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != find[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_file_map(char *str)
{
	while (*str)
	{
		if (*str == '.')
		{
			if (check_file(str, ".ber") != 0)
			{
				ft_putendl_fd("\033[1;31m file not valid\033[0m", 2);
				exit(0);
			}
		}
		str++;
	}
}
