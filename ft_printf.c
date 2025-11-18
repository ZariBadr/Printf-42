#include <stdarg.h>
#include <stdint.h>

int ft_convert(const char str,va_list args)
{
    int nprinted;
    nprinted = 0;

    if (str == 'c')
        nprinted += ft_putchar(va_arg(args,int));
    else if (str == 's')
        nprinted += ft_putstr(va_arg(args,char *));
    else if (str == 'p')
        nprinted += ft_putptr(va_arg(args,uintptr_t));
    else if (str == 'd' || str == 'i')
        nprinted += ft_putnbr(va_arg(args,int));
    else if (str == 'u')
        nprinted += ft_putunsigned(va_arg(args, unsigned int));
    else if (str == 'x' || str == 'X')
        nprinted += ft_puthex(va_arg(args, unsigned int),str);
    else if (str == '%')
        nprinted += ft_putchar('%');
    return (nprinted);
}


int ft_printf(const char * str, ...)
{
    int i;
    int nprinted;
    va_list args;
    va_start(args,str);

    i = 0;
    nprinted = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            nprinted += ft_convert(str[i],args);
            i++;
        }
        else
        {
            nprinted += ft_putchar(str[i]);
        }
    }
}