/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:25:30 by abucia            #+#    #+#             */
/*   Updated: 2022/06/02 09:02:27 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# include "../../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef DIM
#  define DIM 1000
# endif
# ifndef MOV
#  define MOV 30
# endif
# ifndef ATIME
#  define ATIME 4
# endif
# define NB_LAYER 3
# define EXTENTION ".xpm"

//# define K_UP 65362
//# define K_RT 65363
//# define K_LT 65361
//# define K_DN 65364

# define K_W 13
# define K_LINUX_W 13
# define K_R 15
# define K_LINUX_R 15

# define K_A 0
# define K_LINUX_A 0
# define K_S 1
# define K_LINUX_S 1
# define K_D 2
# define K_LINUX_D 2
# define K_G 5
# define K_LINUX_G 5

# define K_V 9
# define K_B 11
# define K_LINUX_B 11

# define K_1 18
# define K_LINUX_1 18
# define K_2 19
# define K_LINUX_2 19
# define K_3 20
# define K_LINUX_3 20
# define K_4 21
# define K_LINUX_4 21
# define K_5 23
# define K_LINUX_5 23
# define K_6 22
# define K_LINUX_6 22
# define K_7 26
# define K_LINUX_7 26
# define K_8 28
# define K_LINUX_8 28
# define K_9 25
# define K_LINUX_9 25
# define K_0 29
# define K_LINUX_0 29

# define PV_0 82
# define PV_1 83
# define PV_2 84
# define PV_3 85
# define PV_4 86
# define PV_5 87
# define PV_6 88
# define PV_7 89
# define PV_8 91
# define PV_9 92

# define K_DEL 51
# define K_ESC 53
# define K_LINUX_ESC 53

# define K_UP 126
# define K_LT 123
# define K_DN 125
# define K_RT 124
//# define O_RDONLY	0x0000

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		w;
	int		h;
}	t_data;
typedef struct s_map {
	int		end_game;
	int		nb_wall;
	int		nb_void;
	int		nb_player;
	int		nb_collect;
	int		nb_exit;
	int		nb_enemy;
	int		l;
	int		h;
	char	**map;
	t_pos	player;
	t_data	img;
	char	*c;
	char	a;
}	t_map;

typedef struct s_animation
{
	unsigned int	step;
	int				replace;
	int				visible;
	int				score;
	int				anime_time;
	char			dir;
	int				last_anime;
	int				l_build;
	int				h_build;
	char			****tab_layer_p;
	void			*mlx;
	void			*mlx_win;
	int				keycode;
	int				r;
	int				g;
	int				b;
	int				calcx;
	int				calcy;
	t_data			*nu;
	t_data			*obj;
	t_data			*left;
	t_data			*right;
	t_data			*up;
	t_data			*down;
	t_data			*stand_l;
	t_data			*stand_r;
	t_data			*stand_u;
	t_data			*stand_d;
	t_data			*floor;
	t_data			*wall;
	t_data			*exit;
	t_data			layer;
	t_data			map;
	t_map			the_map;
	t_pos			calc_pos;
	t_pos			futur_pos;
	t_pos			pos;
}	t_animation;

//ERROR AND FREE
void		er_txt(int i, t_animation txt, char *er);
void		read_error(int fd, char *str, char *er);
void		free_p_tab(char ***p, t_pos v);
void		er_pointer_tab(t_animation *txt, int i, t_pos v, char *str);
void		er_cam_pointer_tab(t_animation *txt, t_pos v);
void		ft_ermap(char *str);
void		stop_all(t_map map, t_animation txt);
int			txt_stop_all(t_animation txt, t_data *side, int nb);
void		free_build_map(t_map map, int current_h, char *er);
int			my_destroy_img(void *mlx, t_data *data, int nb);
int			stop(t_animation *txt);

//FILES
t_animation	init_texture(t_animation txt, t_map map);
t_animation	*colision(t_animation *txt, t_map *map, int i);
int			key_press(int keycode, t_animation *txt);
int			key_release(int keycode, t_animation *txt);
int			manage_rgb(int keycode, t_animation *txt);
void		manage_theme(int keycode, t_animation *txt);
int			manage_mov(int keycode, t_animation *txt);
void		manage_spectator(int keycode, t_animation *txt);
void		sort_animation(t_map *map, t_animation *txt);

//PARSER
t_map		map_checker(t_map map, int i, int j);
t_map		map_parser(char *path);
char		*ft_readall(int fd);
t_map		line_parser(char *line, int fd);

//TXT
char		***pointer_tab(t_animation *txt, t_data *data, int i, t_pos v);
void		build_map(t_map map, t_animation *txt);
void		ft_sort(t_pos v, t_map map, t_animation *txt);
char		*ft_test_pos(int x, int y, t_map map, char a);
int			try(char *src, const char *str, int i);
void		change_exit(t_animation *txt);

//UTILS
void		ft_putstr(char *str);
void		ft_putnbr(unsigned int nb);
size_t		ft_strlen(const char *str);
char		*ft_strdup(char *s1);
char		*ft_freestrjoin(char *s1, char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);

//MLX UTILS
void		my_mlx_put_nb(int nb, int pix, t_animation txt, int h);
void		my_camera(t_data *data, t_animation txt);
void		put_pixel_cam(char ***dst, t_pos v_txt, t_pos neg, t_animation txt);
void		optimize_pos_calc(t_animation *txt, t_map *map, t_pos i);
void		put_player(t_data src, t_animation txt);
void		my_mlx_img_put(t_data *data, t_data src, t_pos v);
t_pos		init_t_pos(int i, int j);
void		make_img(t_animation *txt, t_map *map);
#endif
