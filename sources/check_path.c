/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/06 10:10:12 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
void	check_lr(char *location, int *found)
{
	if (*(location + 1) != '1' && *(location + 1) != '2')
	{
		if (*(location + 1) == 'C')
			*found = *found + 1;
		*(location + 1) = '2';
	}
	if (*(location - 1) != '1' && *(location - 1) != '2')
	{
		if (*(location - 1) == 'C')
			*found = *found + 1;
		*(location - 1) = '2';
	}
}

static
void	check_ud(char *location, int *found, t_map *map)
{
	if (*(location + map->width) != '1' && *(location + map->width) != '2')
	{
		if (*(location + map->width) == 'C')
			*found = *found + 1;
		*(location + map->width) = '2';
	}
	if (*(location - map->width) != '1' && *(location - map->width) != '2')
	{
		if (*(location - map->width) == 'C')
			*found = *found + 1;
		*(location - map->width) = '2';
	}
}

static
void	check_surrounding(char *location, int *found, t_map *map)
{
	check_lr(location, found);
	check_ud(location, found, map);
}

static
void	init(char **map_cpy, char **map_buffer, int *csr, t_map *map)
{
	*map_cpy = ft_strdup(map->data);
	*map_buffer = ft_strdup(map->data);
	if (!map_cpy)
		free(map_cpy);
	if (!map_buffer)
		free(map_buffer);
	if (!map_cpy || !map_buffer)
		error(map, 0);
	*csr = 0;
}

void	check_path(t_map *map)
{
	char	*map_cpy;
	char	*map_buffer;
	int		cursor;
	int		found;

	init(&map_cpy, &map_buffer, &cursor, map);
	while (*(map_cpy + cursor) != 'P')
		cursor++;
	*(map_cpy + cursor) = '2';
	found = 0;
	while (ft_strncmp(map_buffer, map_cpy, map->width * map->height))
	{
		free(map_buffer);
		map_buffer = check_ft_strdup(map_cpy, map);
		cursor = 0;
		while (*(map_cpy + cursor))
			if (*(map_cpy + cursor++) == '2')
				check_surrounding(map_cpy + cursor - 1, &found, map);
	}
	free(map_cpy);
	free(map_buffer);
	if (found != map->collectible)
		error(map, 6);
}
