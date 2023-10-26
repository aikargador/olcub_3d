#include "cub69d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

bool	allocate_plr(t_plr *plr) // chk if allocation failed and return false!
{
	plr->cords = ft_calloc(1, sizeof(t_cords));
	plr->del = ft_calloc(1, sizeof(t_cords));
	return (true);
}

int main() {
	t_able	table;
	t_mlx	mlx;
	t_map	map;
	t_plr	plr;

	
	table.mlx = &mlx;
	table.map = &map;
	table.plr = &plr;
	table.keys[0] = 0;
	table.keys[1] = 0;
	table.keys[2] = 0;
	table.keys[3] = 0;
	table.blk_sz = 64;
	table.mv_speed = 1;
	allocate_plr(&plr);
	table.plr->cords = ft_calloc(1, sizeof(t_cords));
	table.plr->del = ft_calloc(1, sizeof(t_cords));

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 512, 512, "poopy!");
	if (!mlx.win_ptr)
	{
		free(mlx.win_ptr);
		return (1);//before that destroy everything else!
	}
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, 512, 512);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	map_init(&map, table.blk_sz);
	draw_map(&table);
	blayer_blacement(&table);
	mlx_loop_hook(mlx.mlx_ptr, (int (*)(void *))handle_events, &table);
	mlx_hook(mlx.win_ptr, 02, 1L<<0, &handle_keypress, &table); /* ADDED */
	mlx_hook(mlx.win_ptr, 03, 1L<<1, &handle_keyrelease, &table); /* CHANGED */
	mlx_hook(mlx.win_ptr, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
