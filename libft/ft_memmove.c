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
void	*movefromback(void *dest, const void *src, size_t n)
{
	size_t	cursor;

	cursor = n;
	while (cursor--, cursor > 0)
		*((char *) dest + cursor) = *((char *) src + cursor);
	*((char *) dest + cursor) = *((char *) src + cursor);
	return (dest);
}

static
void	*movefromfront(void *dest, const void *src, size_t n)
{
	size_t	cursor;

	cursor = 0;
	while (cursor++, cursor <= n)
		*((char *) dest + cursor - 1) = *((char *) src + cursor - 1);
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	if (dest > src)
		return (movefromback(dest, src, n));
	return (movefromfront(dest, src, n));
}
