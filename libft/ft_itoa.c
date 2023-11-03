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
long long int	ft_abs(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static
int	ft_intlen(long long int n)
{
	int	result;

	if (n == 0)
		return (1);
	if (n < 0)
		result = 1;
	else
		result = 0;
	n = ft_abs(n);
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static
int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		negative;
	int		len;
	char	*result;

	negative = ft_sign(n);
	len = ft_intlen(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (0);
	while (len > 0)
	{
		*(result + len - 1) = ft_abs(n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (negative)
		*result = '-';
	return (result);
}
