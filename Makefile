CFILES = ft_printf.c \
		ft_printf_int.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_printf_unsigned.c \
		ft_putnbr_hex.c \
		ft_print_adress.c \
		ft_strlen.c


OFILES = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar crs $(NAME) $(OFILES)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
