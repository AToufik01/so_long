/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:54:12 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/08 15:43:52 by ataoufik         ###   ########.fr       */
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

int	check_cara(char *str, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (str[i] != s[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_file_map(char *str)
{
	int	i;

	i = 0;
	if (check_cara(str, "maps/") == 1)
	{
		ft_putendl_fd("\033[1;31merror !\nmap outside of folder\033[0m", 2);
		exit(0);
	}
	while (*str)
	{
		if (*str == '.')
		{
			if (check_file(str, ".ber") != 0)
			{
				ft_putendl_fd("\033[1;31merror !\nfile not valid\033[0m", 2);
				exit(0);
			}
		}
		str++;
	}
}
