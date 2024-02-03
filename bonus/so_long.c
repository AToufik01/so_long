/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:37:40 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/01 17:50:51 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *mp)
{
	destroy_img(mp);
	exit(0);
}

void	update_posi(int keycode, t_map *mp)
{
	int	new_x;
	int	new_y;

	new_x = mp->p_x;
	new_y = mp->p_y;
	if (keycode == 126 || keycode == 13)
		new_y -= 1;
	else if (keycode == 125 || keycode == 1)
		new_y += 1;
	else if (keycode == 123 || keycode == 0)
	{
		mp->img_p = mp->img_p_r;
		new_x -= 1;
	}
	else if (keycode == 124 || keycode == 2)
	{
		mp->img_p = mp->img_p_l;
		new_x += 1;
	}
	else if (keycode == 53 || keycode == 17)
	{
		destroy_img(mp);
		exit(0);
	}
	check_wall(mp, mp->arr, new_x, new_y);
}

void	draw_and_print(t_map *mp)
{
	mlx_clear_window(mp->mlx, mp->mlx_win);
	mlx_put_image_to_window(mp->mlx, mp->mlx_win, mp->img_b, 0, 0);
	object_mps(mp);
}

int	key_press(int keycode, t_map *mp)
{
	update_posi(keycode, mp);
	if (mp->n == mp->n_c)
		mp->index_c = 1;
	else
		mp->index_c = 0;
	draw_and_print(mp);
	return (0);
}

int	main(int arc, char *arv[])
{
	t_map	mp;

	mp.src = arv[1];
	if (arc != 2)
		return (0);
	mp.frame_count = 0;
	check_file_map(mp.src);
	mp.mlx = mlx_init();
	if (!mp.mlx)
		return (1);
	ft_initialization_s(&mp);
	validation_maps(&mp);
	mp.mlx_win = mlx_new_window(mp.mlx, mp.w_mp * 60, mp.h_mp * 60, "so_long");
	mlx_put_image_to_window(mp.mlx, mp.mlx_win, mp.img_b, 0, 0);
	mlx_hook(mp.mlx_win, 2, 0, key_press, &mp);
	object_mps(&mp);
	mlx_loop_hook(mp.mlx, update_frame, &mp);
	mlx_hook(mp.mlx_win, 17, 0, close_window, &mp);
	mlx_loop(mp.mlx);
	return (0);
}
