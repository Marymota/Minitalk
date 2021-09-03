#include "libft.h"

size_t	ft_intlen(int i)
{
	int	idx;

	idx = 0;
	if (i == -2147483648)
		return (11);
	if (i < 10 && i > -1)
		return (1);
	if (i < 0)
	{
		++idx;
		i = i * -1;
	}
	while (i > 9)
	{
		i /= 10;
		++idx;
	}
	if (i >= 0)
		++idx;
	return (idx);
}
