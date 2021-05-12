#include "includes/ft_printf.h"
#include <stdio.h>

int main (void)
{
    int c = -12;
    int a = 4;
    ft_printf("test %.*d\n",a,c);
    printf("test %.*d",a,c);
}