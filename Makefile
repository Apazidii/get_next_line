NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
MAKE = Makefile

FUNCS		=		get_next_line.c				get_next_line_utils.c
FUNCS_B		=		get_next_line_bonus.c		get_next_line_utils_bonus.c

FUNCS_O		=		$(FUNCS:.c=.o)
FUNCS_O_B	=		$(FUNCS_B:.c=.o)

HDR			=		get_next_line.h
HDR_B		=		get_next_line_bonus.h

.c.o: $(FUNCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(FUNCS_O)
	$(AR) $@ $^

$(FUNCS_O): $(HDR) $(MAKE) 

$(FUNCS_O_B): $(HDR_B) $(MAKE)

bonus: $(FUNCS_O_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(FUNCS_O) $(FUNCS_O_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re