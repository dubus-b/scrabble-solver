CXX     = 	g++

RM      = 	rm -rf

NAME    = 	scrable-solver

INDIR   = 	./include/

SRCDIR  = 	./sources/

SRCS    = 	$(SRCDIR)main.cpp 			\
			$(SRCDIR)dictionary.cpp

OBJS    = 	$(SRCS:.cpp=.o)

CXXFLAGS += 	-W -Wall -Wextra -Werror -std=c++11 -I $(INDIR)

all : 		$(NAME)

$(NAME) : 	$(OBJS)
	  	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean :
		$(RM) $(OBJS)

fclean :	 clean
		$(RM) $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re
