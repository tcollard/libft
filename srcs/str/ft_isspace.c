#include "../../includes/libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
	c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
