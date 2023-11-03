/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/03 21:09:54 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit(1);
	map = load_map(*(argv + 1));
	check_map(map);
	free(map->data);
	free(map);
	return (0);
}
