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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	cursor;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	cursor = 0;
	while (cursor < ft_strlen(s1) + ft_strlen(s2))
	{
		if (cursor < ft_strlen(s1))
			*(result + cursor) = *(s1 + cursor);
		else
			*(result + cursor) = *(s2 + cursor - ft_strlen(s1));
		cursor++;
	}
	*(result + cursor) = 0;
	return (result);
}
