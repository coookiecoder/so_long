/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/11/03 20:59:51 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
void	ft_free(char *data, char *buffer)
{
	if (buffer)
		free(buffer);
	free(data);
}

static
void	put_data(t_map *map, char *data)
{
	char	*buffer;

	if (map->data)
	{
		buffer = ft_calloc((map->width * (map->height + 1)) + 1, 1);
		if (!buffer || (int)ft_strlen(data) - 1 != map->width)
		{
			ft_free(data, buffer);
			error(map, 1);
		}
		ft_strlcpy(buffer, map->data, ((map->width) * (map->height)++) + 1);
		buffer = ft_strjoin(buffer, data);
		map->data = buffer;
		return ;
	}
	map->data = ft_calloc(ft_strlen(data), 1);
	if (!map->data)
	{
		free(data);
		error(map, 0);
	}
	ft_strlcpy(map->data, data, ft_strlen(data));
	map->width = ft_strlen(data) - 1;
	map->height = 1;
}

t_map	*load_map(const char	*location)
{
	int		file_map;
	char	*buffer_line;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error(map, 0);
	file_map = open(location, O_RDONLY);
	map->width = 0;
	map->height = 0;
	buffer_line = get_next_line(file_map);
	while (buffer_line)
	{
		put_data(map, buffer_line);
		free(buffer_line);
		buffer_line = get_next_line(file_map);
	}
	return (map);
}
