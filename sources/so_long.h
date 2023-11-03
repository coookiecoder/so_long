/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/03 21:03:59 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// user in error.c and load_map.c

# include <stdlib.h>

// used in load_map.c

# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_map {
	char	*data;
	int		height;
	int		width;
}	t_map;

// function in error.c

void	error(t_map *map, int error_number);

// function in load_map.c

t_map	*load_map(const char	*location);

// function in show_map.c

void	show_map(t_map *map);

// function in check_map.c

void	check_map(t_map *map);

#endif
