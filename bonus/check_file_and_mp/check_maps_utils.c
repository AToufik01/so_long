/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:37:20 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/01 17:30:48 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_cont_heidth(const char *str, char c)
{
	int	cont;

	cont = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			cont++;
		while (*str != c && *str)
			str++;
	}
	return (cont);
}

char	**read_maps(t_map *mp)
{
	char	*str;
	char	*res;

	res = NULL;
	mp->fd = open(mp->src, O_RDONLY);
	str = get_next_line(mp->fd);
	mp->w_mp = ft_strlen(str) - 1;
	while (str)
	{
		res = ft_strjoin(res, str);
		free(str);
		str = get_next_line(mp->fd);
	}
	mp->arr = ft_split(res, '\n');
	mp->h_mp = ft_cont_heidth(res, '\n');
	close(mp->fd);
	return (mp->arr);
}

int	check_border_map(t_map *mp)
{
	int	i;
	int	w;
	int	h;

	w = mp->w_mp;
	h = mp->h_mp;
	i = 0;
	while (mp->arr[0][i] && mp->arr[h - 1][i])
	{
		if (mp->arr[0][i] == '1' && mp->arr[h - 1][i] == '1')
			i++;
		else
			return (-1);
	}
	i = 0;
	while (mp->arr[i])
	{
		if (mp->arr[i][0] == '1' && mp->arr[i][w - 1] == '1')
			i++;
		else
			return (-1);
	}
	return (1);
}

void	validation_maps(t_map *mp)
{
	if (check_one_player(mp) != 1)
		ft_putendl_fd("\033[1;31m error player\033[0m", 2);
	else if (character_autoris(mp) != 1)
		ft_putendl_fd("\033[1;31m error character\033[0m", 2);
	else if (check_one_exit(mp) != 1)
		ft_putendl_fd("\033[1;31m error exit\033[0m", 2);
	else if (check_coins(mp) != 1)
		ft_putendl_fd("\033[1;31m error coins\033[0m", 2);
	else if (check_border_map(mp) != 1)
		ft_putendl_fd("\033[1;31m Map  incorrect\033[0m", 2);
	else if (!ft_place_use(mp, duplicat(mp)))
		ft_putendl_fd("\033[1;31m error item rounded by wall\033[0m", 2);
	else
		return ;
	exit(0);
}
