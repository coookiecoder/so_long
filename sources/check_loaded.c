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

mlx_texture_t	*c_png(const char *location, mlx_image_t *img[6], \
t_map *map, mlx_texture_t *old)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(location);
	if (!texture)
		error_img(map, img);
	if (old)
		mlx_delete_texture(old);
	return (texture);
}

void	check_loaded(mlx_image_t *img[6], t_map *map)
{
	int	cursor;

	cursor = 0;
	while (cursor < 6)
	{
		if (!img[cursor++])
			error_img(map, img);
	}
}

char	*c_ft_strjoin(char *s1, char *s2, int mode)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (result);
}

char	*check_ft_strdup(char *s, t_map *map)
{
	char	*buffer;

	buffer = ft_strdup(s);
	if (!buffer)
	{
		free(s);
		error(map, 0);
	}
	return (buffer);
}
