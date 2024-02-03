/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_enviro2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:21 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/01 00:33:29 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_exit(t_map *mp, int i, int j)
{
	if (mp->index_c == 1)
		mlx_put_image_to_window(mp->mlx, mp->mlx_win, mp->img_eo,
			j * 60, i * 60);
	else
		mlx_put_image_to_window(mp->mlx, mp->mlx_win, mp->img_ec,
			j * 60, i * 60);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		n_digit;

	n_digit = 0;
	num = n;
	while (num != 0)
	{
		n_digit++;
		num /= 10;
	}
	if (n == 0)
		n_digit = 1;
	str = (char *)malloc(n_digit + 1);
	str[n_digit] = '\0';
	while (n_digit)
	{
		str[n_digit - 1] = n % 10 + '0';
		n /= 10;
		n_digit--;
	}
	return (str);
}

void	number_move(t_map *mp)
{
	char	*str;

	str = ft_itoa(mp->n_move);
	mlx_string_put(mp->mlx, mp->mlx_win, 10, 0, 0xFFFFFF, "move = ");
	mlx_string_put(mp->mlx, mp->mlx_win, 90, 0, 0xFFFFFF, str);
	free(str);
}
