NAME= npuzzle

SRC_PATH= ./src/
OBJ_PATH= ./obj/
INC_PATH= ./inc/
LFT_PATH = ./libft/

SRC_NAME= 	main.c \
			utils.c \
			parser.c \
			heuristic.c \
			puzzle.c \
			common_search.c \
			a_star_search.c \
			greedy_search.c \
			uniform_cost_search.c \
			t_btree.c \
			debug.c

OBJ_NAME= $(SRC_NAME:.c=.o)

#CFLAGS= -Werror -Wextra -Wall
CFLAGS= -fsanitize=address -g
LDFLAGS = -L$(LFT_PATH) -fsanitize=address -g

LDLIBS= -lm -lft

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)	
	gcc $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) -o $@ -c $< -I$(INC_PATH) -I$(LFT_PATH)

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C $(LFT_PATH) clean

fclean: clean
	rm -fv $(NAME)
	make -C $(LFT_PATH) fclean

re:	fclean all
