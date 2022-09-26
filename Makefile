NAME	= containers

SRC		=	main.cpp

OBJ		= $(SRC:.cpp=.o)

HEADER	=	utils/enable_if.hpp\
			utils/equal.hpp\
			utils/is_integral.hpp\
			utils/lexicographical_compare.hpp\
			utils/pair.hpp\
			utils/red_black_tree.hpp\
			iterators_utils/iterators_traits.hpp\
			iterators_utils/node_iterator.hpp\
			iterators_utils/reverse_iterator.hpp\
			iterators_utils/vector_iterator.hpp\
			containers/vector.hpp\
			containers/map.hpp\
			containers/stack.hpp\
			containers/set.hpp

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all		: $(NAME)

$(NAME)	: $(OBJ) $(HEADR)
		$(CC) $(CFAGS) $(OBJ) -o $(NAME)

.cpp.o	: $(HEADR)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)

re		: fclean all

.PHONY	: clean fclean re all