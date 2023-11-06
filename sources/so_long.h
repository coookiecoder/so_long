/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/06 10:07:09 by abareux          ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map {
	char	*data;
	int		height;
	int		width;
	int		move;
	int		collectible;
	int		collected;
	mlx_t	*mlx;
}	t_map;

// function in error.c

void			error_img(t_map *map, mlx_image_t *img[6]);
void			error(t_map *map, int error_number);

// function in load_map.c

t_map			*load_map(const char *location);

// function in show_move.c

void			show_move(t_map *map);

// function in check_map.c

_Bool			check_win(t_map *map);
void			check_map(t_map *map);

// function in check_path.c

void			check_path(t_map *map);

// funcrion in move.c

int				move_up(t_map *map);
int				move_down(t_map *map);
int				move_right(t_map *map);
int				move_left(t_map *map);

// function in check_loaded.c

void			check_loaded(mlx_image_t *img[6], t_map *map);
mlx_texture_t	*c_png(const char *location, mlx_image_t *img[6], \
t_map *map, mlx_texture_t *texture);
char			*c_ft_strjoin(char *s1, char *s2, int mode);
char			*check_ft_strdup(char *s, t_map *map);

#endif
