# Declaration of variables
CC = clang++
#-ggdb for other info
CC_FLAGS =-std=c++14

# File names
EXEC = ./acs_client.exe
SOURCES = $(shell find ./ -type f -name "*.cpp")
SOURCES += $(shell find ../shared/ -type f -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

#This is the default target
#Because of heavy header usage, I clean the project before building.
#Then I build the project in parallel
#Then I remove all the object files as they clutter my editor.
#Then I run the executable
dev: 
	echo Building ACS CLient - DEV MODE
	echo
	echo ************  Formatting Files ************
	$(shell find ../ -type f -name "*.h" -exec clang-format -style=google -i {} \;)
	$(shell find ../ -type f -name "*.cpp" -exec clang-format -style=google -i {} \;)
	echo
	echo ************  Cleaning Files ************
	$(MAKE) clean
	echo
	echo ************  MAKING ALL IN PARALLEL ************
	$(MAKE) all -j 8
	echo
	echo ************  REMOVING OBJECTS ************
	$(MAKE) rmobj
	echo
	echo ************  RUNNING EXECUTABLE TEST ************
	$(EXEC) test1

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