/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_enviro2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:21 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/01 00:01:43 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_exit(t_map *mp, int i, int j)
{
	if (mp->index_c == 1)
		mlx_put_image_to_window(mp->mlx, mp->mlx_win,
			mp->img_eo, j * 60, i * 60);
	else
		mlx_put_image_to_window(mp->mlx, mp->mlx_win,
			mp->img_ec, j * 60, i * 60);
}
