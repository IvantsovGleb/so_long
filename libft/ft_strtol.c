#include "libft.h"

static int  uo_flow(int sign, unsigned long *nbr, int base, int c)
{
    unsigned long   cutoff;
    int             cutlim;

    cutoff = (unsigned long)LONG_MAX / (unsigned long)base;
    if (sign)
        cutlim = (unsigned long)LONG_MIN % (unsigned long)base;
    else
        cutlim = (unsigned long)LONG_MAX % (unsigned long)base;
    if (*nbr > cutoff || (*nbr == cutoff && c > cutlim))
    {
        if (sign)
            *nbr = LONG_MIN;
        else
            *nbr = LONG_MAX;
        return (ERANGE);
    }
    return (0);
}

static int  define_base(const char **sp, const char **endp, int base)
{
    if (**sp == '0')
    {
        (*sp)++;
        *endp = *sp;
        if ((base == 0 || base == 16) && (**sp == 'x' || **sp == 'X'))
        {
            (*sp)++;
            base = 16;
        }
        else
            base = 8;
    }
    else if (base == 0)
        base = 10;
    return (base);
}

static long  to_integer(const char **sp, const char **endp, int sign, int base, int *errn)
{
    unsigned long   nbr;
    int             c;

    nbr = 0;
    while (1)
    {
        if (ft_isalpha((unsigned char)**sp))
            c = ((**sp - 'A') & (~('a' ^ 'A'))) + 10;
        else if (ft_isdigit((unsigned char)**sp))
            c = **sp - '0';
        else
            break;
        if (c >= base)
            break;
        *endp = ++*sp;
        *errn = uo_flow(sign, &nbr, base, c);
        if (!*errn)
            nbr = nbr * base + c;
    }
    return ((long)nbr);
}

long    ft_strtol(const char *nptr, char **endptr, int base, int *errn)
{
    int             sign;
    unsigned long   nbr;
    const char      *sp;
    const char      *endp;

    sp = nptr;
    endp = nptr;
    while (ft_isspace((unsigned char)*sp))
        sp++;
    sign = 0;
    if (*sp == '+' || *sp == '-')
        sign = (*sp++ == '-');
    base = define_base(&sp, &endp, base);
    nbr = to_integer(&sp, &endp, sign, base, errn);
    if (!*errn && sign)
        nbr = -nbr;
    if (endptr)
        *endptr = (char *)endp;
    return ((long)nbr);
}
