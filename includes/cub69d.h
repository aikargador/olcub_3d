#ifndef CUB69D_H
# define CUB69D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define BLK 64
# define DtR PIw / 180
# define RtD 180 / PIw
# define PIw 3.1415926536
# define PIe PIw * 2
# define PIn PIw / 2
# define PIs (3 * PIw) / 2

typedef struct s_cords {
	double	x;
	double	y;
}				t_cords;

typedef	struct	s_plr {
	t_cords	*cords;
	t_cords	*del;
	double	angl;
}				t_plr;

typedef struct	s_map {
	short	map_xy;
	short	map_s;
	int		**map;
}				t_map;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img_data	img;
}				t_mlx;


typedef struct	s_table {
	t_mlx	*mlx;
	t_map	*map;
	t_plr	*plr;


	short	blk_sz;
	short	plr_height;
	short	fov;
	short	keys[4];
	double	mv_speed;






	// double	del_x;
	// double	del_y;
	// double	x;
	// double	y;
}					t_able;

/* main.c */
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

// /* utils */
// /* map_maker.c */
void	map_init(t_map *map, short element_sz);
void	draw_map(t_able *table);
void	main_ray(t_able *table);

// /* blayer.c */
void	blayer_blacement(t_able *table);
// void	blayer_angle(t_able *table, t_cords *xy, t_cords *del);
// void	blayer_movement(t_able *table, t_cords *xy, t_cords *del_xy, double ang);
void	blayer_movement(t_able *table, t_cords *xy);

// /* ray_casta.d */
// void	le_ray_caste(t_able *table, t_cords *xy, t_cords *del, double ang);
// void	le_ray_caste_angel(t_able *table, t_cords *xy, t_cords *del, double ang);

// /* rr0.c */
bool	chk_up(double angle);
bool	chk_down(double angle);
bool	chk_right(double angle);
bool	chk_left(double angle);


// /* utils0.c */
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

/* movements */
void	plyr_rt(t_able *table);
void	plyr_rrt(t_able *table);
bool	plyr_mv_forward(t_able *table);
bool	plyr_mv_backward(t_able *table);
bool	plyr_rt_and_mv(t_able *table, int rt, int mv);

/* event handler */
int ft_close(t_mlx *mlx);
int	handle_events(t_able *table);
int	handle_keypress(int keysym, t_able *table);
int	handle_keyrelease(int keysym, t_able *table);

/* mini_libft */
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif