# Declaration of variables
CC = g++
CC_FLAGS = -w -std=c++14 -g
OBJ_DIR = ./obj/

# File names
EXEC = acs_client
SOURCES = $(shell find ./ -type f -name "*.cpp")
SOURCES += $(shell find ../shared/ -type f -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files 
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

.PHONY : all
all : $(EXEC)