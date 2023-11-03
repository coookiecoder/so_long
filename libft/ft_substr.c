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

static
char	*ft_empty(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (0);
	*ptr = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rptr;
	size_t	cursor;

	if (start > ft_strlen(s))
		return (ft_empty());
	if (len > ft_strlen(s))
		rptr = malloc(ft_strlen(s) + 1);
	else if (start + len > ft_strlen(s))
		rptr = malloc(ft_strlen(s) - start + 1);
	else
		rptr = malloc(len + 1);
	if (!rptr)
		return (0);
	cursor = 0;
	while (cursor < len && cursor < ft_strlen(s))
	{
		*(rptr + cursor) = *(s + start + cursor);
		cursor++;
	}
	*(rptr + cursor) = 0;
	return (rptr);
}
