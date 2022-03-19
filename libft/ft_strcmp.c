#include "libft.h"

int	ft_strcmp(const char *p1, const char *p2)
{
    const char	*s1;
    const char	*s2;

    s1 = p1;
    s2 = p2;
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}