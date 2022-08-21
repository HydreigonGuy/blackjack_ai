
cc	=	g++

#	SOURCES	#

SRC		=	Card.cpp	\
			Deck.cpp	\
			Player.cpp	\
			Game.cpp

TESTS_SRC	=

$(eval SRC = $(addprefix src/, $(SRC)))

#	OBJECTS	#

OBJ	=	$(SRC:.cpp=.o)

TESTS_OBJ	=	$(TESTS_SRC:.cpp=.o)

#	NAME	#

NAME1	=	human

TESTS_NAME	=	unit_tests

#	FLAGS	#

CXXFLAGS	=	-W -Wpedantic -Wall -Wextra -fno-builtin -I./include/

TESTS_FLAGS	=	--coverage -lcriterion

#	RULES	#

all:	$(NAME1)

$(NAME1):	$(OBJ)
	@printf "\033[1;36m Compiling .C\n"
	@$(cc) -o $(NAME1) $(OBJ) human_game_main.cpp $(CFLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

tests_run: $(OBJ)	$(TESTS_OBJ)
	@printf "\033[1;36m Compiling .C\n"
	@$(cc) -o $(TESTS_NAME) $(OBJ) $(TESTS_OBJ) $(TESTS_FLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

clean:
	@printf "\033[1;31m Cleanning .o\n"
	@rm -f $(OBJ) $(TESTS_OBJ)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

fclean: clean
	@printf "\033[1;31m Cleanning binaries\n"
	@rm -f $(NAME1) $(TESTS_NAME)
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m cleanning vgcore\n"
	@rm -f vgcore.*
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

re:	fclean	all
	@printf "\033[1;32m REBULDING DONE\n"
	@printf "\033[00m"
