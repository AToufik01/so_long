/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiali_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:40:44 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/04 19:47:16 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_in_pc(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp->arr[i])
	{
		j = 0;
		while (mp->arr[i][j])
		{
			if (mp->arr[i][j] == 'P')
			{
				mp->p_x = j;
				mp->p_y = i;
			}
			if (mp->arr[i][j] == 'C')
				mp->n_c++;
			j++;
		}
		i++;
	}
}

void	ft_initialization_s(t_map *mp)
{
	mp->n_c = 0;
	mp->n = 0;
	if ((open(mp->src, O_RDONLY)) == -1)
		exit(0);
	read_maps(mp);
	initialization_demon(mp);
	mp->n_move = 0;
	ft_in_pc(mp);
	set_image(mp);
	mp->img_demon = mp->img_demon_r;
	mp->img_p = mp->img_p_l;
}

void	set_image(t_map *mp)
{
	mp->img_b = xmp(mp, "imageusd/background.xpm", 0);
	mp->img_p_l = xmp(mp, "imageusd/playerl.xpm", 1);
	mp->img_p_r = xmp(mp, "imageusd/playerr.xpm", 2);
	mp->img_c_r = xmp(mp, "imageusd/coins5.xpm", 3);
	mp->img_c_l = xmp(mp, "imageusd/coins1.xpm", 4);
	mp->img_ec = xmp(mp, "imageusd/exitc.xpm", 5);
	mp->img_eo = xmp(mp, "imageusd/exito.xpm", 6);
	mp->img_w = xmp(mp, "imageusd/wall.xpm", 7);
	mp->img_demon_l = xmp(mp, "imageusd/demonl.xpm", 8);
	mp->img_demon_r = xmp(mp, "imageusd/demonr.xpm", 9);
	mp->images[0] = mp->img_b;
	mp->images[1] = mp->img_p_l;
	mp->images[2] = mp->img_p_r;
	mp->images[3] = mp->img_c_r;
	mp->images[4] = mp->img_c_l;
	mp->images[5] = mp->img_ec;
	mp->images[6] = mp->img_eo;
	mp->images[7] = mp->img_w;
	mp->images[8] = mp->img_demon_l;
	mp->images[9] = mp->img_demon_r;
}

void	destroy_img(t_map *mp)
{
	mlx_destroy_image(mp->mlx, mp->img_b);
	mlx_destroy_image(mp->mlx, mp->img_p_l);
	mlx_destroy_image(mp->mlx, mp->img_p_r);
	mlx_destroy_image(mp->mlx, mp->img_ec);
	mlx_destroy_image(mp->mlx, mp->img_eo);
	mlx_destroy_image(mp->mlx, mp->img_w);
	mlx_destroy_image(mp->mlx, mp->img_c_l);
	mlx_destroy_image(mp->mlx, mp->img_c_r);
	mlx_destroy_image(mp->mlx, mp->img_demon_l);
	mlx_destroy_image(mp->mlx, mp->img_demon_r);
}

void	*xmp(t_map *mp, char *filname, int i)
{
	void	*img;
	int		e;

	img = mlx_xpm_file_to_image(mp->mlx, filname, &e, &e);
	if (!img)
	{
		while (i <= 0)
		{
			mlx_destroy_image(mp->mlx, mp->images[i]);
			i--;
		}
		ft_putendl_fd("\033[1;31m Error: Failed to load image\033[0m", 2);
		free_2darr(mp->arr);
		exit(0);
	}
	return (img);
}
