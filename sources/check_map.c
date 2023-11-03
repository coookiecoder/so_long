/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/03 21:10:43 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
void	send_error(int nbentry, int nbexit, int nbcollectibles, t_map *map)
{
	if (nbentry != 1)
		error(map, 2);
	if (nbexit != 1)
		error(map, 3);
	if (nbcollectibles < 1)
		error(map, 4);
}

static
void	check_entry_exit_collectible(t_map *map)
{
	int	cursor;
	int	nbentry;
	int	nbexit;
	int	nbcollectible;

	cursor = 0;
	nbentry = 0;
	nbexit = 0;
	nbcollectible = 0;
	while (cursor < map->width * map->height)
	{
		if (*(map->data + cursor) == 'P')
			nbentry++;
		if (*(map->data + cursor) == 'E')
			nbexit++;
		if (*(map->data + cursor) == 'C')
			nbcollectible++;
		cursor++;
	}
	send_error(nbentry, nbexit, nbcollectible, map);
}

static
void	check_wall(t_map *map)
{
	int	cursor;

	cursor = 0;
	while (cursor < map->width * map->height)
	{
		if (cursor < map->width)
			if (*(map->data + cursor) != '1')
				error(map, 5);
		if (cursor % map->width == 0)
			if (*(map->data + cursor) != '1')
				error(map, 5);
		if (cursor % map->width == map->width - 1)
			if (*(map->data + cursor) != '1')
				error(map, 5);
		if (cursor > map->width * (map->height - 1) - 1)
			if (*(map->data + cursor) != '1')
				error(map, 5);
		cursor++;
	}
}

void	check_map(t_map *map)
{
	check_entry_exit_collectible(map);
	check_wall(map);
}
