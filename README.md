# Ft_printf
## Because ft_putnbr() and ft_putstr() aren’t enough
### The goal of this project is pretty straightforward. You will recode printf(). You will mainly learn about using a variable number of arguments. How cool is that?? It is actually pretty cool :)

## How to use

clone the repository
```bash
git clone https://github.com/pyven-dr/ft_printf.git
```
compile
```bash
make
```

include `ft_printf.h` to use it

```c
#include "ft_printf.h"

int  main(void)
{
    ft_printf("Hello world !\n");
    return(0);
}
```

Output should be
```bash
Hello world !
```

## Available conversion

| Format specifier | Description                                                          |
| ---------------- | -----------                                                          |
| `%c`             | Prints a single character.                                           |
| `%s`             | Prints a string (as defined by the common C convention).             |
| `%p`             | The void * pointer argument has to be printed in hexadecimal format. |
| `%d`             | Prints a decimal (base 10) number.                                   |
| `%i`             | Prints an integer in base 10.                                        |
| `%u`             | Prints an unsigned decimal (base 10) number.                         | 
| `%x`             | Prints a number in hexadecimal (base 16) lowercase format.           |
| `%X`             | Prints a number in hexadecimal (base 16) uppercase format.           |
| `%%`             | Prints a percent sign.                                               |
