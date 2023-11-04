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

void	error(t_map *map, int error_number)
{
	if (error_number == -1)
		write(1, "File name error\n", 16);
	else if (error_number)
	{
		free(map->data);
		free(map);
		write(1, "Error\n", 7);
		write(1, "Map invalid\n", 13);
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
	exit(error_number);
}
