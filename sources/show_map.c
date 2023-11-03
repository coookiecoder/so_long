/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/03 19:56:41 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_map(t_map *map)
{
	int	line;

	line = 0;
	ft_putendl_fd(ft_itoa(map->width), 1);
	ft_putendl_fd(ft_itoa(map->height), 1);
	while (line < map->height)
	{
		write(1, map->data + (line++ *map->width), map->width);
		write(1, "\n", 1);
	}
}
