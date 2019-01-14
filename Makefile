CC		:= gcc
WFLAGS	:= -Wall -Wextra
RM		:= rm -rf
NAME	:= ft_ls 

SRCDIR	:= srcs

SRC		:= ft_ls.c arg_parser.c exits.c options.c free.c print_helpers.c ldir.c append_path.c opt_l.c
INCL	:= -I includes/ -I libft/includes

LIBS	:= -L libft -lft
SRCS	:= $(addprefix $(SRCDIR)/, $(SRC))
LS		:= $(SRCS)

OBJS	:= $(LS:.c=.o)
DEPS	:= Makefile includes/ft_ls.h

COMP	:= $(CC) $(WFLAGS) $(INCL) $(LIBS)
OPT		:= -l /

all: $(NAME)

diff: all
	@./$(NAME) $(OPT) > a
	@ls -C $(OPT) > b
	@diff a b
	@$(RM) a
	@$(RM) b

ls: all
	@ls -C $(OPT)

ben: all
	echo
	ls -la
	echo
	./ft_ls .

d: all
	@./$(NAME) $(OPT)

l: all
	@$(COMP) test.c
	@./a.out

val: all
	@valgrind --leak-check=yes ./$(NAME)
	@$(RM) $(NAME)

fsa:
	@$(COMP) $(LS) -fsanitize=address -g3
	@./a.out $(OPT)
	@$(RM) a.out*

$(NAME): $(OBJS)
	@make -C libft
	@$(COMP) -o $(NAME) $(LS)
	
%.o: %.c $(DEPS)
	@$(CC) -o $@ -c $< $(WFLAGS) $(INCL)

clean:
	@make clean -C libft
	@$(RM) *dSYM*
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)
	@$(RM) a.out

re: fclean all

.PHONY: all clean fclean re d fsa val
