CC		:= gcc
WFLAGS	:= -Wall -Wextra
RM		:= rm -rf
NAME	:= ft_ls 

SRCDIR	:= srcs

SRC		:= ft_ls.c arg_parser.c exits.c options.c free.c print_helpers.c
INCL	:= -I includes/

SRCS	:= $(addprefix $(SRCDIR)/, $(SRC))
LS		:= $(SRCS)

OBJS	:= $(LS:.c=.o)
DEPS	:= Makefile includes/ft_ls.h

COMP	:= $(CC) $(WFLAGS) $(LS) $(INCL)

all: $(NAME)

d: all
	@./$(NAME) -la

l: all
	@$(COMP) listdir.c
	@./a.out || true

val: all
	@valgrind --leak-check=yes ./a.out
	@$(RM) a.out*

fsa:
	@$(COMP) -fsanitize=address -g3
	@./a.out
	@$(RM) a.out*

$(NAME): $(OBJS)
	$(COMP) -o $(NAME)
	
%.o: %.c $(DEPS)
	@$(CC) -o $@ -c $< $(WFLAGS) $(INCL)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) a.out

re: fclean all

.PHONY: all clean fclean re d fsa val
