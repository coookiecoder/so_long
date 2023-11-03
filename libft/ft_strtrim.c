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
void	ft_cpy(const char *src, char *dst, int n)
{
	int	cursor;

	cursor = 0;
	while (cursor < n)
	{
		*(dst + cursor) = *(src + cursor);
		cursor++;
	}
	*(dst + cursor) = 0;
	return ;
}

static
int	ft_checkset(const char *s, char const *set)
{
	int	cursor;
	int	nbchar;

	cursor = 0;
	nbchar = ft_strlen(set);
	while (cursor < nbchar)
	{
		if (*s == *(set + cursor))
			return (1);
		cursor++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	size;
	size_t	start;
	size_t	end;

	size = ft_strlen(s1);
	start = 0;
	end = size;
	while (ft_checkset(s1 + start, set) && start < size / 2)
		start++;
	while (ft_checkset(s1 + end - 1, set) && end > size / 2)
		end--;
	result = malloc(end - start + 1);
	if (!result)
		return (0);
	ft_cpy(s1 + start, result, end - start);
	return (result);
}
