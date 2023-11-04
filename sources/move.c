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

static
char	check_first_move(t_map *map)
{
	if (map->move)
		return ('M');
	return ('P');
}

int	move_up(t_map *map)
{
	int	cursor;

	cursor = 0;
	while (*(map->data + cursor) != check_first_move(map))
		cursor++;
	if (*(map->data + cursor - map->width) == 'P')
		return (0);
	if (*(map->data + cursor - map->width) != '1')
	{
		if (*(map->data + cursor - map->width) == 'C')
			map->collected++;
		if (*(map->data + cursor - map->width) == 'E')
		{
			if (map->collectible != map->collected)
				return (0);
		}
		*(map->data + cursor - map->width) = 'M';
		if (map->move)
			*(map->data + cursor) = '0';
		map->move++;
		return (1);
	}
	return (0);
}

int	move_down(t_map *map)
{
	int	cursor;

	cursor = 0;
	while (*(map->data + cursor) != check_first_move(map))
		cursor++;
	if (*(map->data + cursor + map->width) == 'P')
		return (0);
	if (*(map->data + cursor + map->width) != '1')
	{
		if (*(map->data + cursor + map->width) == 'C')
			map->collected++;
		if (*(map->data + cursor + map->width) == 'E')
		{
			if (map->collectible != map->collected)
				return (0);
		}
		*(map->data + cursor + map->width) = 'M';
		if (map->move)
			*(map->data + cursor) = '0';
		map->move++;
		return (1);
	}
	return (0);
}

int	move_right(t_map *map)
{
	int	cursor;

	cursor = 0;
	while (*(map->data + cursor) != check_first_move(map))
		cursor++;
	if (*(map->data + cursor + 1) == 'P')
		return (0);
	if (*(map->data + cursor + 1) != '1')
	{
		if (*(map->data + cursor + 1) == 'C')
			map->collected++;
		if (*(map->data + cursor + 1) == 'E')
		{
			if (map->collectible != map->collected)
				return (0);
		}
		*(map->data + cursor + 1) = 'M';
		if (map->move)
			*(map->data + cursor) = '0';
		map->move++;
		return (1);
	}
	return (0);
}

int	move_left(t_map *map)
{
	int	cursor;

	cursor = 0;
	while (*(map->data + cursor) != check_first_move(map))
		cursor++;
	if (*(map->data + cursor - 1) == 'P')
		return (0);
	if (*(map->data + cursor - 1) != '1')
	{
		if (*(map->data + cursor - 1) == 'C')
			map->collected++;
		if (*(map->data + cursor - 1) == 'E')
		{
			if (map->collectible != map->collected)
				return (0);
		}
		*(map->data + cursor - 1) = 'M';
		if (map->move)
			*(map->data + cursor) = '0';
		map->move++;
		return (1);
	}
	return (0);
}
