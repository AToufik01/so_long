/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_enviro1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:28:37 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/04 19:49:06 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_map *mp, int new_x, int new_y, int keycode)
{
	if ((mp->arr[new_y][new_x] != '1') && (keycode == 126 ||
			keycode == 13 || keycode == 125 || keycode == 1 ||
			keycode == 123 || keycode == 0 || keycode == 124 || keycode == 2))
	{
		mp->n_move++;
		mp->p_x = new_x;
		mp->p_y = new_y;
		if (mp->arr[new_y][new_x] == 'C')
		{
			mp->n++;
			mp->arr[new_y][new_x] = '0';
		}
		else if (mp->arr[new_y][new_x] == 'E' && mp->index_c == 1)
		{
			free_2darr(mp->arr);
			printwin();
		}
	}
}

void	put_walls(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp->h_mp)
	{
		j = 0;
		while (j < mp->w_mp)
		{
			if (mp->arr[i][j] == '1')
				mlx_put_image_to_window(mp->mlx, mp->mlx_win,
					mp->img_w, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	put_coins(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp->h_mp)
	{
		j = 0;
		while (j < mp->w_mp)
		{
			if (mp->arr[i][j] == 'C')
				mlx_put_image_to_window(mp->mlx, mp->mlx_win, mp->img_c,
					j * 60 + 10, i * 60 + 20);
			j++;
		}
		i++;
	}
}

void	put_play_exit(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp->h_mp)
	{
		j = 0;
		while (j < mp->w_mp)
		{
			if (mp->arr[i][j] == 'E')
				put_img_exit(mp, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mp->mlx, mp->mlx_win, mp->img_p,
		mp->p_x * 60 + 10, mp->p_y * 60 + 20);
	mlx_put_image_to_window(mp->mlx, mp->mlx_win, mp->img_demon,
		mp->demon_x * 60 + 10, mp->demon_y * 60 + 20);
}

void	object_mps(t_map *mp)
{
	put_walls(mp);
	put_coins(mp);
	put_play_exit(mp);
	number_move(mp);
}
