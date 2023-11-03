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

char	*ft_strrchr(const char *s, char c)
{
	int		cursor;
	char	*result;

	cursor = 0;
	result = 0;
	while (*(s + cursor))
	{
		if (*(s + cursor) == c)
			result = (char *)s + cursor;
		cursor++;
	}
	if (*(s + cursor) == c)
		return ((char *)s + cursor);
	return (result);
}
