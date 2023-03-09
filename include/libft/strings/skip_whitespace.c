#include "../libft.h"

# define WHITESPACE " \n\t\v\r\f"

void	skip_whitespaces(char **str)
{
	if (!*str || !**str)
		return ;
	while (**str && ft_isset(**str, WHITESPACE))
		*str += 1;
	return ;
}
