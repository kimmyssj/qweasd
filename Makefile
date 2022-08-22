NAME = libftprintf.a

SRC_A = ft_base_changer.c ft_memory.c ft_int_uint_per.c \
		ft_str_char.c ft_printf.c ft_strchr.c \

OBJ_A = $(SRC_A:.c=.o)

AR = ar

ARFLAG = -rcs

CC = cc

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_A)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $<

clean :
	rm -f $(OBJ_A)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
