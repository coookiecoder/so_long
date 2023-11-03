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

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cursor;
	size_t	offset;

	cursor = 0;
	offset = ft_strlen(dst);
	if (size <= offset)
		return (ft_strlen(src) + size);
	while (*(src + cursor) && offset + cursor + 1 < size)
	{
		if (cursor < size - offset - 1)
			*(dst + cursor + offset) = *(src + cursor);
		cursor++;
	}
	*(dst + cursor + offset) = '\0';
	return (offset + ft_strlen(src));
}
