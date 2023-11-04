/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/04 15:43:18 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
void	load_asset(mlx_image_t *img[6], t_map *map)
{
	mlx_texture_t *texture;

	if (map->move)
	{
		mlx_delete_image(map->mlx, img[0]);
		mlx_delete_image(map->mlx, img[1]);
		mlx_delete_image(map->mlx, img[2]);
		mlx_delete_image(map->mlx, img[3]);
		mlx_delete_image(map->mlx, img[4]);
		mlx_delete_image(map->mlx, img[5]);
	}
	texture = mlx_load_png("asset/floor.png");
	img[0] = mlx_texture_to_image(map->mlx, texture);
	texture = mlx_load_png("asset/wall.png");
	img[1] = mlx_texture_to_image(map->mlx, texture);
	texture = mlx_load_png("asset/Collectible.png");
	img[2] = mlx_texture_to_image(map->mlx, texture);
	texture = mlx_load_png("asset/Player.png");
	img[3] = mlx_texture_to_image(map->mlx, texture);
	texture = mlx_load_png("asset/DoorIn.png");
	img[4] = mlx_texture_to_image(map->mlx, texture);
	texture = mlx_load_png("asset/DoorOut.png");
	img[5] = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
}

static
void	send_image(t_map *map, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(map->mlx, img, x * 32, y * 32);
}

static
void	calc_img(t_map *map)
{
	static mlx_image_t	*img[6];
	int					c;

	load_asset(img, map);
	c = 0;
	while (c < map->width * map->height)
	{
		send_image(map, img[0], c % map->width, c / map->height);
		if (*(map->data + c) == '1')
			send_image(map, img[1], c % map->width, c / map->height);
		if (*(map->data + c) == 'C')
			send_image(map, img[2], c % map->width, c / map->height);
		if (*(map->data + c) == 'M' || (*(map->data + c) == 'P' && !map->move))
			send_image(map, img[3], c % map->width, c / map->height);
		if (*(map->data + c) == 'E')
			send_image(map, img[4], c % map->width, c / map->height);
		if (*(map->data + c) == 'P')
			send_image(map, img[5], c % map->width, c / map->height);
		c++;
	}
}

static
void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (check_win(param))
		return ;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		if (move_up(param))
			calc_img(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (move_down(param))
			calc_img(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (move_right(param))
			calc_img(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (move_left(param))
			calc_img(param);
	if (keydata.action == MLX_PRESS)
		show_move(param);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	mlx_t		*mlx;

	if (argc != 2)
		exit(1);
	map = load_map(*(argv + 1));
	check_map(map);
	map->move = 0;
	map->collected = 0;
	mlx = mlx_init(map->width * 32, map->height * 32, "so_long", true);
	map->mlx = mlx;
	calc_img(map);
	mlx_key_hook(mlx, &my_keyhook, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map->data);
	free(map);
	return (0);
}
