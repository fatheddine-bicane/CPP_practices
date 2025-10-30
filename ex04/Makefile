TARGET = fileFormatter
SOURCE_FILE = ./Sources/*.cpp
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILER = c++


GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


#--------------------------------------------------------#

.phony : all clean re

all : $(TARGET)

$(TARGET) : $(SOURCE_FILE)
	@echo "$(GREEN)Building fileFormatter$(RESET)"
	@$(COMPILER) $(CPP_FLAGS) $(SOURCE_FILE) -o $(TARGET)

clean :
	@echo "$(RED)Removing fileFormatter$(RESET)"
	@rm -f fileFormatter

re : clean all
