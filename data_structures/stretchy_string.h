#ifndef STRETCHY_STRING_H
# define STRETCHY_STRING_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_string
{
    char    *d;
    int     n;
    int     i;
}           t_string;

void        t_string_init(void *s);
void        t_string_copy(void *dst, const void *src);
void        t_string_destructor(void *s);
void        t_string_push_back(t_string *s, char ch);

char    *reallocation(char **d, int old_n, int new_n);
void    mem_free(char  **data);

#endif
