TARGET = addressManipulation
SOURCE_FILE = ./Main.cpp
OBJ_FILE = ./Main.o
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILER = c++


GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


#--------------------------------------------------------#

.phony : all clean fclean re

all : $(TARGET)

$(TARGET) : $(OBJ_FILE)
	@echo "$(GREEN)Building addressManipulation$(RESET)"
	@$(COMPILER) $(CPP_FLAGS) $(OBJ_FILE) -o $(TARGET)

%.o : %.cpp
	@$(COMPILER) $(CPP_FLAGS) -c $< -o $@

clean :
	@echo "$(RED)Removing object files$(RESET)"
	@rm -f $(OBJ_FILES)


fclean : clean
	@echo "$(RED)Removing addressManipulation$(RESET)"
	@rm -f addressManipulation

re : clean all
