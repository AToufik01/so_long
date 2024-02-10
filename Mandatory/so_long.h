/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataoufik <ataoufik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:37:42 by ataoufik          #+#    #+#             */
/*   Updated: 2024/02/10 14:54:45 by ataoufik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_nl/get_next_line.h"
# include "mlx.h"
# define MAX_IMAGES 7

typedef struct s_map
{
	char	**arr;
	void	*images[MAX_IMAGES];
	int		fd;
	int		w_mp;
	int		h_mp;
	int		indx;
	void	*img_b;
	void	*img_p;
	void	*img_p_l;
	void	*img_p_r;
	void	*img_c;
	void	*img_ec;
	void	*img_eo;
	void	*img_w;
	void	*mlx;
	char	*src;
	void	*mlx_win;
	int		b_h;
	int		b_w;
	int		p_x;
	int		p_y;
	int		n_c;
	int		index_c;
	int		n_move;
	int		n;
}	t_map;

int		ft_cont_heidth(const char *str, char c);
char	**read_maps(t_map *mp);
void	free_2darr(char **str);
int		check_border_map(t_map *mp);
void	validation_maps(t_map *mp);
int		check_one_player(t_map *mp);
int		character_autoris(t_map *mp);
int		check_one_exit(t_map *mp);
int		check_coins(t_map *mp);
void	f_s_p_usd(int x, int y, char **arr, int *items_count);
int		ft_place_use(t_map *map, char *dup_arr[]);
char	**duplicat(t_map *mp);
void	check_file_map(char *str);
int		check_file(char *str, char *find);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_initialization_s(t_map *mp);
void	set_image(t_map *mp);
void	destroy_img(t_map *mp);
void	*xmp(t_map *mp, char *filname, int i);
void	check_wall(t_map *mp, int new_x, int new_y, int keycode);
void	put_walls(t_map *mp);
void	put_coins(t_map *mp);
void	put_play_exit(t_map *mp);
void	object_mps(t_map *mp);
void	put_img_exit(t_map *mp, int i, int j);
int		close_window(t_map *mp);
void	update_posi(int keycode, t_map *mp);
void	draw_and_print(t_map *mp);
int		key_press(int keycode, t_map *mp);
void	printwin(void);
#endif