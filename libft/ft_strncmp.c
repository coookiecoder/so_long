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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cursor;
	unsigned char	*c1;
	unsigned char	*c2;

	cursor = 0;
	while (cursor < n && *(s1 + cursor) && *(s2 + cursor))
	{
		c1 = (unsigned char *)s1 + cursor;
		c2 = (unsigned char *)s2 + cursor;
		if (*c1 != *c2)
			return (*c1 - *c2);
		cursor++;
	}
	if (cursor != n)
	{
		c1 = (unsigned char *)s1 + cursor;
		c2 = (unsigned char *)s2 + cursor;
		return (*c1 - *c2);
	}
	return (0);
}
