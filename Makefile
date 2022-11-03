CC = gcc

FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

NAME = push_swap
NAME_BONUS = checker

SOURCES = check_sorted.c count_tabs.c do_rotations.c fill_tabs.c find_pivot.c insertion_sort.c insertion_sort2.c main.c operations.c operations2.c print.c quick_sort.c quick_sort2.c sort_2.c sort_3.c stacks.c utils.c
SRCS = $(addprefix ./srcs/, $(SOURCES))

SOURCES_BONUS = checker.c stacks.c fill_tabs.c count_tabs.c check_sorted.c utils.c print.c stdin.c operations_bonus.c operations2_bonus.c operations3_bonus.c
BONUS = $(addprefix ./srcs/, $(SOURCES_BONUS))

OBJECTS = ${SOURCES:.c=.o}
OBJS = $(addprefix ./objs/, $(OBJECTS))

OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}
OBJS_BONUS = $(addprefix ./objs/, $(OBJECTS_BONUS))

HEADER = ./includes

all : $(NAME)

$(NAME) :	$(OBJS)
		gcc $(FLAGS) -o $(NAME) $(OBJS)

clean : 
		rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean 
		rm -f $(NAME) $(NAME_BONUS)

re :	fclean all

bonus :		$(OBJS_BONUS)
		gcc $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

./objs/%.o :	./srcs/%.c
		mkdir -p objs
		$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

.PHONY : all re clean fclean bonus
