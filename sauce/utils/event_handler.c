/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:48:55 by aikram            #+#    #+#             */
/*   Updated: 2023/10/14 19:55:09 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

//experimental institution

// void	blyr_rt(t_able *table)
// {
// 	table->plr->angl += 0.1;
// 	if (table->plr->angl > PIe)
// 		table->plr->angl -= PIe;
// 	table->plr->del->x = cos(table->plr->angl) * table->mv_speed;
// 	table->plr->del->y = sin(table->plr->angl) * table->mv_speed;
// 	return ;
// }

// /* a */
// void	blyr_rrt(t_able *table)
// {
// 	table->plr->angl -= 0.1;
// 	if (table->plr->angl < 0)
// 		table->plr->angl += PIe;
// 	table->plr->del->x = cos(table->plr->angl) * table->mv_speed;
// 	table->plr->del->y = sin(table->plr->angl) * table->mv_speed;
// 	return ;
// }

// bool	blyr_mv_forward(t_able *table)
// {
// 	int pp = (int)((table->plr->cords->y + table->plr->del->y \
// 	* table->mv_speed) / BLK);
// 	pp *= 8;
// 	pp += (int)((table->plr->cords->x + table->plr->del->x \
// 	* table->mv_speed) / BLK);
// 	if (table->map->map[pp] == 1)
// 		return (false);
// 	table->plr->cords->x += table->plr->del->x * table->mv_speed;
// 	table->plr->cords->y += table->plr->del->y * table->mv_speed;
// 	return (true);
// }

// bool	blyr_mv_backward(t_able *table)
// {
// 	int pp = (int)((table->plr->cords->y - table->plr->del->y \
// 	* table->mv_speed) / BLK);
// 	pp *= 8;
// 	pp += (int)((table->plr->cords->x - table->plr->del->x \
// 	* table->mv_speed) / BLK);
// 	if (table->map->map[pp] == 1)
// 		return (false);
// 	table->plr->cords->x -= table->plr->del->x * table->mv_speed;
// 	table->plr->cords->y -= table->plr->del->y * table->mv_speed;
// 	return (true);
// }

// bool	blyr_mv_and_rt(t_able *table, int rt, int mv)
// {
// 	if (rt)
// 		plyr_rt(table);
// 	else
// 		plyr_rrt(table);
// 	if (mv)
// 		return (plyr_mv_forward(table));
// 	else
// 		return (plyr_mv_backward(table));
// }






int ft_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit (0); //make sure to clear em memmo
	// return (0);
}

void	handle_movements(t_able *table)
{
	if (table->keys[3] && table->keys[0]) // w a
		plyr_rt_and_mv(table, 0, 1);
	else if (table->keys[3] && table->keys[2]) // w d
		plyr_rt_and_mv(table, 1, 1);
	else if (table->keys[1] && table->keys[0]) // s a
		plyr_rt_and_mv(table, 0, 0);
	else if (table->keys[1] && table->keys[2]) // s d
		plyr_rt_and_mv(table, 1, 0);
	else if (table->keys[0]) // a
		plyr_rrt(table);
	else if (table->keys[1]) // s
		plyr_mv_backward(table);
	else if (table->keys[2]) // d
		plyr_rt(table);
	else if (table->keys[3]) // w
		plyr_mv_forward(table);
	if (table->keys[0] || table->keys[1] || table->keys[2] || table->keys[3])
		main_ray(table);
}

int	handle_events(t_able *table)// 2.0
{
	t_cords	xy;
	t_cords	del_xy;
	double	ang;

	ang = table->plr->angl;
	xy.x = table->plr->cords->x;
	xy.y = table->plr->cords->y;
	del_xy.x = table->plr->del->x;
	del_xy.y = table->plr->del->y;
	handle_movements(table);
	blayer_movement(table, &xy);
	mlx_put_image_to_window(table->mlx->mlx_ptr, table->mlx->win_ptr, table->mlx->img.img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_able *table)
{
	// printf("%d\n", keysym);
	if (keysym == 53) {
		mlx_destroy_window(table->mlx->mlx_ptr, table->mlx->win_ptr);
		exit (0); //make sure to clear em memmo
	}
	else if (keysym == 0)
		table->keys[0] = 1;
	else if (keysym == 1)
		table->keys[1] = 1;
	else if (keysym == 2)
		table->keys[2] = 1;
	else if (keysym == 13)
		table->keys[3] = 1;
	return (0);
}

int	handle_keyrelease(int keysym, t_able *table)
{
	if (keysym == 0)
		table->keys[0] = 0;
	else if (keysym == 1)
		table->keys[1] = 0;
	else if (keysym == 2)
		table->keys[2] = 0;
	else if (keysym == 13)
		table->keys[3] = 0;
	return (0);
}
