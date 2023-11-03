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
void	ft_getsign(const char *c, int *sign, int *cursor)
{
	if (*c == '+')
		*sign = 1;
	else if (*c == '-')
		*sign = -1;
	else
		*sign = 0;
	*cursor = *cursor + 1;
	return ;
}

static
int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	cursor;
	int	sign;
	int	result;

	cursor = 0;
	result = 0;
	while (ft_isspace(*(nptr + cursor)))
		cursor++;
	if (!ft_isdigit(*(nptr + cursor)))
		ft_getsign(nptr + cursor, &sign, &cursor);
	else if (ft_isdigit(*(nptr + cursor)))
		sign = 1;
	while (*(nptr + cursor) == '0')
		cursor++;
	while (ft_isdigit(*(nptr + cursor)))
	{
		result *= 10;
		result += *((char *)nptr + cursor) - '0';
		cursor++;
	}
	return (result * sign);
}
