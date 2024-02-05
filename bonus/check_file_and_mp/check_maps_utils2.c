/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:00:08 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/04 19:55:33 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_2darr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	f_s_p_usd(int x, int y, char **arr, int *items_count)
{
	if (arr[y][x] == '1' || arr[y][x] == 'F')
		return ;
	if (arr[y][x] == 'C' || arr[y][x] == 'E')
		*items_count += 1;
	arr[y][x] = 'F';
	f_s_p_usd(x + 1, y, arr, items_count);
	f_s_p_usd(x - 1, y, arr, items_count);
	f_s_p_usd(x, y + 1, arr, items_count);
	f_s_p_usd(x, y - 1, arr, items_count);
}

int	ft_place_use(t_map *map, char *dup_arr[])
{
	int	items_count;
	int	i;

	i = 0;
	items_count = 0;
	f_s_p_usd(map->p_x, map->p_y, dup_arr, &items_count);
	free_2darr(dup_arr);
	if (items_count == map->n_c + 1)
		return (1);
	return (0);
}

char	**duplicat(t_map *mp)
{
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc((mp->h_mp + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (i < mp->h_mp)
	{
		str[i] = ft_strdup(mp->arr[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
