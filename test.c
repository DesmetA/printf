#include "includes/ft_printf.h"
#include <stdio.h>

int main (void)
{
    ft_printf("%% *.5i 42 == |% *.5i|", 4, 42);
}