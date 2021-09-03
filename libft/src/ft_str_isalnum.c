#include "libft.h"

int	ft_str_isalnum(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-')
		++i;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		++i;
	}
	return (1);
}
