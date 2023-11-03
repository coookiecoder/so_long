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

#define INT_MAX 2147483647

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	cursor;

	if (nmemb * size > INT_MAX)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	cursor = 0;
	while (cursor < nmemb * size)
	{
		*((char *)ptr + cursor) = 0;
		cursor++;
	}
	return (ptr);
}
