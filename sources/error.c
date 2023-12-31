/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_img(t_map *map, mlx_image_t *img[6])
{
	int	cursor;

	cursor = 0;
	while (cursor < 6)
	{
		if (img[cursor])
			mlx_delete_image(map->mlx, img[cursor]);
		cursor++;
	}
	free(map->data);
	free(map);
	write(1, "error while loading asset\n", 27);
	exit(-1);
}

void	error(t_map *map, int error_number)
{
	if (error_number == -1)
		write(1, "File name error\n", 16);
	else if (error_number)
	{
		write(1, "Error\nMap Invalid\n", 19);
		if (error_number == 2)
			write(1, "Wrong start number\n", 20);
		if (error_number == 3)
			write(1, "Wrong exit number\n", 19);
		if (error_number == 4)
			write(1, "Wrong collectible number\n", 26);
		if (error_number == 5)
			write(1, "Missing wall outside\n", 22);
		if (error_number == 6)
			write(1, "No path found\n", 15);
	}
	else
		write(1, "Malloc error\n", 14);
	if (map)
		if (map->data)
			free (map->data);
	if (map)
		free(map);
	exit(error_number);
}
