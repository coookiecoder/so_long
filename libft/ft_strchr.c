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

char	*ft_strchr(const char *s, char c)
{
	int	cursor;

	cursor = 0;
	while (*(s + cursor))
	{
		if (*(s + cursor) == c)
			return ((char *) s + cursor);
		cursor++;
	}
	if (*(s + cursor) == c)
		return ((char *) s + cursor);
	return (0);
}
