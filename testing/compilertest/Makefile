# Declaration of variables
CC = clang++
CC_FLAGS = -w -std=c++14 -g

# File names
EXEC = hello_world
SOURCES = $(shell find ./ -type f -name "*.cpp")
#SOURCES += $(shell find ../shared/ -type f -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

#This is the default target
#Because of heavy header usage, I clean the project before building.
#Then I build the project in parallel
#Then I remove all the object files as they clutter my editor.
dev: 
	$(MAKE) clean
	$(MAKE) all -j 8
	$(MAKE) rmobj

# Exec target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files 
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

rmobj:
	rm -f $(OBJECTS)

.PHONY : all
all : $(EXEC)