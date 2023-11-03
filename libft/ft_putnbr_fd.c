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
int	power(int n)
{
	int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	cursor;

	if (n == 0)
		ft_putchar_fd(48, fd);
	if (n == 0)
		return ;
	if (n < 0)
		ft_putchar_fd(45, fd);
	cursor = ft_intlen(n);
	while (cursor)
		ft_putchar_fd(ft_abs(n / power(cursor--) % 10) + 48, fd);
}
