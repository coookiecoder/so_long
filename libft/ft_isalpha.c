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

static
int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c);
	return (0);
}

static
int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (c);
	return (0);
}
