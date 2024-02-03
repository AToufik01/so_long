/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_enviro3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:17 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/02 23:14:19 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_frame(t_map *mp)
{
	if (mp->frame_count % 10 == 0)
		move_demon(mp);
	if (mp->frame_count % 44 == 0)
		mp->img_c = mp->img_c_r;
	else if (mp->frame_count % 44 == 22)
		mp->img_c = mp->img_c_l;
	if (mp->p_y == mp->demon_y && mp->p_x == mp->demon_x)
	{
		destroy_img(mp);//
		printgameover();
	}
	draw_and_print(mp);
	mp->frame_count++;
	return (0);
}

int	demon_valid_p(t_map *mp, int x, int y)
{
	return ((mp->arr[y][x] == '0' && mp->arr[y][x - 1] != '1')
			|| (mp->arr[y][x] == '0' && mp->arr[y][x + 1] != '1')
			|| (mp->arr[y][x] == '0' && mp->arr[y + 1][x] != '1')
			|| (mp->arr[y][x] == '0' && mp->arr[y - 1][x] != '1'));
}

int	initialization_demon(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp->arr[i])
	{
		j = 0;
		while (mp->arr[i][j])
		{
			if (mp->arr[i][j] != 'C' && mp->arr[i][j] != 'E'
				&& mp->arr[i][j] != 'P' && demon_valid_p(mp, j, i))
			{
				mp->demon_x = j;
				mp->demon_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	set_demon_dir(t_map *mp, int d, void *imag)
{
	mp->demon_dir = d;
	mp->img_demon = imag;
}

void	move_demon(t_map *mp)
{
	int	x;
	int	y;

	x = mp->demon_x;
	y = mp->demon_y;
	if (mp->arr[y][x + 1] != '1' && mp->demon_dir == 0)
		mp->demon_x++;
	else if (mp->arr[y][x + 1] == '1' && mp->demon_dir == 0)
		set_demon_dir(mp, 3, mp->img_demon_l);
	if (mp->arr[y][x - 1] != '1' && mp->demon_dir == 1)
		mp->demon_x--;
	else if (mp->arr[y][x - 1] == '1' && mp->demon_dir == 1)
		set_demon_dir(mp, 2, mp->img_demon_r);
	if (mp->arr[y + 1][x] != '1' && mp->demon_dir == 2)
		mp->demon_y++;
	else if (mp->arr[y + 1][x] == '1' && mp->demon_dir == 2)
		mp->demon_dir = 0;
	if (mp->arr[y - 1][x] != '1' && mp->demon_dir == 3)
		mp->demon_y--;
	else if (mp->arr[y - 1][x] == '1' && mp->demon_dir == 3)
		mp->demon_dir = 1;
}
