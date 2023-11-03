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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cursor;

	cursor = 0;
	if (*little == '\0' || big == little)
		return ((char *)big);
	if (len == 0 || ft_strlen(big) < ft_strlen(little))
		return (0);
	if ((int)len < 0)
		len = ft_strlen(big) + (int)len;
	while (cursor < len)
	{
		if (!ft_strncmp(big + cursor, little, ft_strlen(little)))
			if (big + cursor + ft_strlen(little) <= big + len)
				return ((char *)big + cursor);
		cursor++;
	}
	return (0);
}
