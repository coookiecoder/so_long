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
int	ft_count(const char *s, char c)
{
	int	result;
	int	not_separator;

	result = 0;
	not_separator = 0;
	while (*s)
	{
		if (*s != c && not_separator == 0)
		{
			not_separator = 1;
			result++;
		}
		else if (*s == c)
			not_separator = 0;
		s++;
	}
	return (result);
}

static
char	*ft_copy(const char *s, int start, int finish)
{
	char	*result;
	int		cursor;

	cursor = 0;
	result = malloc((finish - start + 1) * sizeof(char));
	if (!result)
		return (0);
	while (start < finish)
		*(result + cursor++) = *(s + start++);
	*(result + cursor) = '\0';
	return (result);
}

static
char	**ft_clear(char **tab)
{
	unsigned int	cursor;

	cursor = 0;
	while (*(tab + cursor))
	{
		free(*(tab + cursor));
		cursor++;
	}
	free(tab);
	return (0);
}

static
void	set_value(int *start, size_t *finish, int *word_cursor)
{
	*start = -1;
	*finish = 0;
	*word_cursor = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		start;
	size_t	finish;
	int		word_cursor;

	result = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (0);
	set_value(&start, &finish, &word_cursor);
	while (finish <= ft_strlen(s))
	{
		if (*(s + finish) != c && start < 0)
			start = finish;
		else if ((*(s + finish) == c || finish == ft_strlen(s)) && start >= 0)
		{
			*(result + word_cursor) = ft_copy(s, start, finish);
			if (!*(result + word_cursor++))
				return (ft_clear(result));
			start = -1;
		}
		finish++;
	}
	*(result + ft_count(s, c)) = 0;
	return (result);
}
