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
int	ft_cmp(const void *s1, const void *s2, int cursor)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	return (*(string1 + cursor) - *(string2 + cursor));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cursor;

	cursor = 0;
	while (cursor < n)
	{
		if (ft_cmp(s1, s2, cursor))
			return (ft_cmp(s1, s2, cursor));
		cursor++;
	}
	if (cursor != n)
		return (ft_cmp(s1, s2, cursor));
	return (0);
}
