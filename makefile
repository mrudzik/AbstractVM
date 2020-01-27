NAME = avm

SRC_DIR :=	./sources/
OBJ_DIR :=	./objects/
INC_DIR :=	./includes/

SRC = 	main.cpp	\
		CommandFactory.cpp		\
		parser/ParserSystem.cpp	\
		parser/LexerModule.cpp	\
		parser/ParserModule.cpp	\
		

#	project object files
OBJ =       $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

INCLUDES	=	-I $(INC_DIR)	\
				-I $(INC_DIR)parser/	\
				-I $(INC_DIR)exceptions/

#FRAMEWORKS	=	
	# For Graphic projects #-w -lSDL2 -w -lSDL2_image -w -lSDL2_ttf

CC_FLAGS := -Wall -Wextra -Werror -O3
CC = clang++ -std=c++14




all:
	make $(NAME)

# compiles .c files
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INCLUDES) 
	# $(FRAMEWORKS) 
	# -g -fsanitize=address
	@ echo "\n===> $(NAME) compiled\n"

#compiles .o files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS) $(INCLUDES)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

vpath %.cpp $(SRC_DIR)