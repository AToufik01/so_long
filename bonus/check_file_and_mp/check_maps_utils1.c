/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:37:01 by ataoufik          #+#    #+#             */
/*   Updated: 2024/01/30 20:22:14 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_one_player(t_map *mp)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (mp->arr[i])
	{
		j = 0;
		while (mp->arr[i][j])
		{
			if (mp->arr[i][j] == 'P')
				n++;
			j++;
		}
		i++;
	}
	if (n == 1)
		return (1);
	else
		return (0);
}

int	character_autoris(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp->arr[i])
	{
		j = 0;
		while (mp->arr[i][j])
		{
			if (mp->arr[i][j] != 'P' && mp->arr[i][j] != '1'
				&& mp->arr[i][j] != '0' && mp->arr[i][j] != 'C'
				&& mp->arr[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_one_exit(t_map *mp)
{
	int	i;
	int	j;
	int	e;

	e = 0;
	i = 0;
	while (mp->arr[i])
	{
		j = 0;
		while (mp->arr[i][j])
		{
			if (mp->arr[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e == 1)
		return (1);
	else
		return (0);
}

int	check_coins(t_map *mp)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (mp->arr[i])
	{
		j = 0;
		while (mp->arr[i][j])
		{
			if (mp->arr[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c > 0)
		return (1);
	else
		return (0);
}
